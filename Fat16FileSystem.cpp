//
// Created by franktominc on 18/01/16.
//

#include "Fat16FileSystem.h"
#include "filler.h"

void Fat16FileSystem::writeToFS() {
    BootSector b(512,128,1,1,2048,0,0xf8,128,32,64,2048,4194304);
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