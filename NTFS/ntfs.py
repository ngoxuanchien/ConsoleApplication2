from attribute import Attribute, unpack_from
import os, struct
def toHex(data):
    hexMap = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    result = ""
    while (data > 0):
        cur = data % 16
        result = hexMap[cur] + result
        data = data // 16
    while (len(result) < 2):
        result = "0" + result
    return result

# http://www.c-jump.com/bcc/t256t/Week04NtfsReview/Week04NtfsReview.html#W01_0140_ntfs_boot_sector_byte
class BootSector:
    def __init__(self, file):
        self.jump = file.read(3)
        self.oem_id = unpack_from(file, 8, is_string=True).strip()
        self.bytes_per_sector = unpack_from(file, 2)
        self.sectors_per_cluster = unpack_from(file, 1)
        file.read(2)
        file.read(1)
        file.read(2)
        file.read(2)
        self.media_descriptor = unpack_from(file, 1)
        file.read(2)
        self.sectors_per_track = unpack_from(file, 2)
        self.number_of_heads = unpack_from(file, 2)
        self.hidden_sectors = unpack_from(file, 4)
        file.read(4)
        file.read(4)
        self.total_sectors = unpack_from(file, 8)
        self.mft_cluster = unpack_from(file, 8)
        self.mft_mirror_cluster = unpack_from(file, 8)
        self.clusters_per_mft_record = unpack_from(file, 1)
        file.read(3)
        self.clusters_per_index_record = unpack_from(file, 1)
        file.read(3)
        self.volume_serial_number = ""
        for i in range(0, 8):
            self.volume_serial_number += toHex(unpack_from(file, 1))
        self.checksum = unpack_from(file, 4)
        self.boot_code = file.read(426)
    def print_atrributes(self):
        print('OEM ID: ', self.oem_id)
        print('Bytes per sector: ', self.bytes_per_sector)
        print('Sectors per cluster: ', self.sectors_per_cluster)
        print('Media descriptor: ', self.media_descriptor)
        print('Sectors per track: ', self.sectors_per_track)
        print('Number of heads: ', self.number_of_heads)
        print('Hidden sectors: ', self.hidden_sectors)
        print('Total sectors: ', self.total_sectors)
        print('MFT cluster: ', self.mft_cluster)
        print('MFTMirr cluster: ', self.mft_mirror_cluster)
        print('Clusters per mft record: ', self.clusters_per_mft_record)
        print('Clusters per index record: ', self.clusters_per_index_record)
        print('Volume serial number: ', self.volume_serial_number)
        print('Checksum: ', self.checksum)


class MFTEntry:
    def __init__(self, file):
        offset = file.tell()
        # Header
        self.signature = unpack_from(file, 4, is_string = True)
        self.fixup_offset = file.read(2)
        self.fixup_count = file.read(2)
        self.lsn = file.read(8)
        self.sequence_number = file.read(2)
        self.link_count = file.read(2)
        self.attributes_offset = unpack_from(file, 2)
        self.flags = file.read(2) # \x03\x00 directory in use
        self.bytes_in_use = unpack_from(file, 4)
        self.bytes_allocated = unpack_from(file, 4)
        self.base_mft_record = file.read(8)
        self.next_attribute_id = file.read(2)

        # Attributes
        self.attributes = []
        file.seek(offset + self.attributes_offset)
        while True:
            attribute = Attribute(file)
            if attribute.attr_type == b'\xff\xff\xff\xff' or file.tell() - offset >= 1024:
                break

            if attribute.attr_type == b'\x30\x00\x00\x00':
                self.attr_file_name = attribute
            elif attribute.attr_type  == b'\x10\x00\x00\x00': 
                self.attr_standard_information = attribute
            elif attribute.attr_type == b'\x80\x00\x00\x00':
                self.attr_data = attribute
            else:
                self.attributes.append(attribute)
    def get_parent_id(self):
        return self.attr_file_name.parent_directory
    def get_name(self):
        file_name = ''
        for c in self.attr_file_name.file_name.encode('ascii'):
            if c != 0:
                file_name += chr(c)
        return file_name
    def get_creation_time(self):
        return self.attr_file_name.creation_time
    def is_dir(self):
        return self.flags == b'\x03\x00'
    def get_data_size(self):
        if hasattr(self, 'attr_data'):
            return self.attr_data.content_length
        else:
            return 'no data'
    def get_file_ext(self):
        return os.path.splitext(self.get_name())[1]
    def get_data_string(self):
        if self.get_file_ext() == '.txt':
            return struct.unpack(f'<{self.attr_data.content_length}s', self.attr_data.content)[0].decode('utf-8')
        else:
            return 'Content of file is not string!'
class MFT:
    def __init__(self, file, dirs):
        offset = file.tell()
        self.mft_entry = MFTEntry(file)
        self.entries = {}
        self.entries[0] = self.mft_entry
        # for i in range(1, 12):
        #     file.seek(offset + i * 1024)
        #     self.entries.append(MFTEntry(file))
        for id in range(25, 43):
            file.seek(offset + id * 1024)
            entry = MFTEntry(file)
            self.entries[id] = entry
            parent = entry.get_parent_id()

            if parent not in dirs:
                dirs[parent] = []
            dirs[parent].append(id)

class NTFS:
    def __init__(self, filename):
        file = open(filename, 'rb')
        self.boot_sector = BootSector(file)
        mft_offset = self.boot_sector.mft_cluster * self.boot_sector.sectors_per_cluster * self.boot_sector.bytes_per_sector
        file.seek(mft_offset)
        self.dirs = {}
        self.mft = MFT(file, self.dirs)
        file.close()
    def get_dir_children(self, dir_id):
        if dir_id in self.dirs:
            return self.dirs[dir_id]
        return []
    def get_file(self, id):
        return self.mft.entries[id]

def is_ntfs_disk(filename):
    try:
        file = open(filename, 'rb')
    except:
        print('Read disk error!')
        return
    file.read(3)
    oem_id = unpack_from(file, 8, is_string=True)
    oem_id = oem_id.strip()
    file.close()
    return oem_id == 'NTFS'