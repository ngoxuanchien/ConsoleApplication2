from ntfs import NTFS, is_ntfs_disk
import os


def handle_dir_cmd(cmd, ntfs, dirs_id):
    if len(cmd) == 1:
        children_ids = ntfs.get_dir_children(dirs_id[-1])

        for id in children_ids:
            file = ntfs.get_file(id)
            print(f'{file.get_creation_time()}', end='\t')
            if file.is_dir():
                print('<dir>', end='\t')
            else:
                print(f'{file.get_data_size()}', end='\t')
            print(f'{file.get_name()}')
    else:
        print('Invalid command')

def handle_cd_cmd(cmd, ntfs, dirs_list, dirs_id):
    if len(cmd) == 1:
        return
    if len(cmd) == 2 and cmd[1] == '.':
        return
    if len(cmd) == 2 and cmd[1] == '..':
        if len(dirs_list) > 1:
            dirs_list.pop()
            dirs_id.pop()
        else:
            print('Cannot go to parent of disk.')
        return
    
    cmd_folder = ' '.join(cmd[1:])
    children_ids = ntfs.get_dir_children(dirs_id[-1])
    for id in children_ids:
        file = ntfs.get_file(id)
        if cmd_folder == file.get_name() and file.is_dir():
            dirs_list.append(cmd_folder)
            dirs_id.append(id)
            return
    print(f'Cannot found folder {cmd_folder}')

def handle_type_cmd(cmd, ntfs, dirs_id):
    if len(cmd) == 1:
        return
    if len(cmd) == 2:
        children_ids = ntfs.get_dir_children(dirs_id[-1])
        for id in children_ids:
            file = ntfs.get_file(id)
            if cmd[1] == file.get_name() and not file.is_dir():
                print(file.get_data_string())
                return
        print('Open file error!!!')
    else:
        print('Invalid command')
        return

def handle_terminal_mode(ntfs, disk):
    dirs_list = [f'{disk}:']
    dirs_id = [5]
    while True:
        path = '\\'.join(dirs_list)
        print(path, end='> ')

        cmd = list(input().split())
        if len(cmd) == 0:
            continue
        if cmd[0] == 'dir' or cmd[0] == 'ls':
            handle_dir_cmd(cmd, ntfs, dirs_id)
        elif cmd[0] == 'cd':
            handle_cd_cmd(cmd, ntfs, dirs_list, dirs_id)
        elif cmd[0] == 'type':
            handle_type_cmd(cmd, ntfs, dirs_id) #cc
        elif cmd[0] == 'exit':
            break
        elif cmd[0] == 'clear' or cmd[0] == 'cls':
            os.system('cls')
        elif cmd[0] == 'help':
            print('dir - list directories')
            print('cd - change directory')
            print('type - print content of text file (.txt)')
            print('exit - exit terminal mode')
            print('clear - clear terminal')
        else:
            print('Invalid command')


def handle_disk_choosing(disk_path, disk):
    ntfs = NTFS(disk_path)
    print(f'NTFS disk {disk} has been successfully inspected.')
    ntfs.boot_sector.print_atrributes()
    print('Enter to continue to terminal mode...')
    input()
    os.system('cls') 
    handle_terminal_mode(ntfs, disk)


if __name__ == "__main__":
    while True:
        os.system('cls') 
        print('Choose NTFS disk to inspect: ', end='')
        disk = input()
        disk = disk.strip()
        disk_path = f'\\\\.\\{disk}:'
        if is_ntfs_disk(disk_path):
            handle_disk_choosing(disk_path, disk)
            break
        else:
            print(f'{disk} is not a valid NTFS disk. Try again.')
        os.system('pause')

    