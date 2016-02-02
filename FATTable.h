//
// Created by ftominc on 1/3/16.
//

#ifndef FAT16_FATTABLE_H
#define FAT16_FATTABLE_H


#include <stdio.h>

class FATTable {
public:
    unsigned short n;
    unsigned short * address;

    FATTable(unsigned short n);

    void writeToFs(FILE * f);
};


#endif //FAT16_FATTABLE_H
