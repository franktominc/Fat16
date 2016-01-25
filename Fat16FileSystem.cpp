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
    fwrite(&b, sizeof(b), 1, file);
    for (int j = 0; j < 63; ++j) {
        filler fi;
        fi.writeToFs(file);
    }
    fwrite(&f, sizeof(f)- sizeof(short),1, file);
    for (int i = 0; i < b.directory_entries; ++i) {
        fwrite(&fe, sizeof(fe), 1, file);
    }

}