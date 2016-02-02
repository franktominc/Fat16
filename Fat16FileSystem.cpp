//
// Created by franktominc on 18/01/16.
//

#include "Fat16FileSystem.h"
#include "filler.h"

void Fat16FileSystem::writeToFS() {
    BootSector b(512,64,1,1,512,65533,0xf8,1,1,1,0,0);
    FATTable f(b.total_sectors);
    FileEntry fe;
    memset(&fe, 0, sizeof(fe));
    b.WriteToFS(file);
    for (int j = 0; j < (b.bytes_per_sector - 512)/512; ++j) {
        filler fi;
        fi.writeToFs(file);
    }

    f.writeToFs(file);
    for (int i = 0; i < b.directory_entries; ++i) {
        fwrite(&fe, sizeof(fe), 1, file);
    }
    printf("%d\n", sizeof(fe));
    for (int k = 0; k < b.sectors_per_cluster*b.total_sectors; ++k) {
        filler fi;
        fi.writeToFs(file);
    }

}