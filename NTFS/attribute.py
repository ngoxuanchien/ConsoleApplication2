from struct import unpack
from datetime import datetime, timedelta, timezone

# https://docs.python.org/3/library/struct.html
def unpack_from(file, bytes, is_string = False):
    f = file.read(bytes)
    if is_string:
        return unpack(f'<{bytes}s', f)[0].decode('utf-8')
    if bytes == 1:
        return unpack('<B', f)[0]
    if bytes == 2:
        return unpack('<H', f)[0]
    if bytes == 3:
        f += b'\x00'
        bytes += 1
    if bytes == 4:
        return unpack('<I', f)[0]
    if bytes < 8:
        f += b'\x00' * (8 - bytes)
        bytes = 8
    if bytes == 8:
        return unpack('<Q', f)[0]
        
def parse_time(nano, format = '%Y-%m-%d %H:%M:%S'):
    epoch = datetime(1601, 1, 1, tzinfo=timezone.utc)
    dt =  epoch + timedelta(seconds=nano // 1e9)
    return str(dt.strftime(format))

class StandardInformation:
    def __init__(self, file, this):
        this.creation_time = unpack_from(file, 8)
        this.modified_time = file.read(8)
        this.mft_modified_time = file.read(8)
        this.accessed_time = file.read(8)
        this.permissions = file.read(4)
        this.max_versions = file.read(4)
        this.version = file.read(4)
        this.class_id = file.read(4)
        this.owner_id = file.read(4)
        this.security_id = file.read(4)
        this.quota_charged = file.read(8)
        this.update_sequence_number = file.read(8)

class FileName:
    def __init__(self, file, this):
        this.parent_directory = unpack_from(file, 6)
        file.read(2)
        this.creation_time = parse_time(unpack_from(file, 8) * 100)
        this.modified_time = file.read(8)
        this.mft_modified_time = file.read(8)
        this.accessed_time = file.read(8)
        this.allocated_size = file.read(8)
        this.real_size = file.read(8)
        this.flags = file.read(4)
        this.reparse_value = file.read(4)
        this.file_name_length = unpack_from(file, 1)
        this.file_name_space = file.read(1)
        this.file_name = unpack_from(file, this.file_name_length*2, is_string=True)

class BitMap:
    def __init__(self, file):
        self.size = unpack_from(file, 1)
        self.cluster_count = unpack_from(file, self.size % 16)
        self.first_cluster = unpack_from(file, self.size // 16)

# http://www.c-jump.com/bcc/t256t/Week04NtfsReview/Week04NtfsReview.html#W01_0220_mft_entry_format
class Attribute:
    def __init__(self, file):
        offset = file.tell()
        # 16 bytes of Header attribte
        self.attr_type = file.read(4)
        if self.attr_type == b'\xff\xff\xff\xff':
            return
        self.attr_length = unpack_from(file, 4)
        self.non_resident_flag = file.read(1)
        self.attr_name_length = unpack_from(file, 1)
        self.attr_name_offset = file.read(2)
        self.attr_flags = file.read(2)
        self.attr_id = file.read(2)

        if self.non_resident_flag == b'\x00':
            # Resident attribute
            self.content_length = unpack_from(file, 4) 
            self.content_offset = file.read(2)
            file.read(1) # indexed_flag
            file.read(1) # padding

            if self.attr_name_length > 0:
                self.attr_name = file.read(self.attr_name_length)

            if self.attr_type == b'\x10\x00\x00\x00':
                StandardInformation(file, self)
            elif self.attr_type == b'\x30\x00\x00\x00':
                FileName(file, self)
            elif self.attr_type == b'\x80\x00\x00\x00':
                self.content = file.read(self.content_length)
        else:
            # Non resident attribute
            self.starting_vcn = file.read(8)
            self.last_vcn = file.read(8)
            self.data_runs_offset = file.read(2)
            self.compress_unit_size = file.read(2)
            file.read(4) # padding
            self.allocated_size = file.read(8)
            self.real_size = file.read(8)
            self.init_data_size = file.read(8)

            if self.attr_name_length > 0:
                self.name = file.read(self.attr_name_length)

            if self.attr_type == b'\xb0\x00\x00\x00':
                self.bitmap = BitMap(file)

        file.seek(offset + self.attr_length)
