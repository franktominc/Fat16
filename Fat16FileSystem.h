//
// Created by franktominc on 18/01/16.
//

#ifndef FAT16_FAT16FILESYSTEM_H
#define FAT16_FAT16FILESYSTEM_H


#include "BootSector.h"
#include "FATTable.h"
#include "FileEntry.h"
#include "filler.h"

class Fat16FileSystem {
    FILE * file;



public:

    Fat16FileSystem(FILE* file):
            file(file){
    }

    void zeroFillFormatter();
    void fastFormatter();
};


#endif //FAT16_FAT16FILESYSTEM_H
