# Accept a directory1, directory2 as cmd arguments, then copy files (*.dll) from directory1 to directory2

import os
import sys

def copy_dlls(dir1, dir2):
    for filename in os.listdir(dir1):
        if filename.endswith('.dll'):
            src = os.path.join(dir1, filename)
            dst = os.path.join(dir2, filename)
            os.system('copy ' + src + ' ' + dst)
            
if __name__ == '__main__':    
    dir1 = sys.argv[1]
    dir2 = sys.argv[2]
    copy_dlls(dir1, dir2)
    