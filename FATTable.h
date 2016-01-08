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
    FATTable(unsigned short n){
        this->n = n;
        address = new unsigned short[n];
        printf("%d\n", (int) sizeof(address));
    }
};


#endif //FAT16_FATTABLE_H
