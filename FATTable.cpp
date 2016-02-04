//
// Created by ftominc on 1/3/16.
//

#include "FATTable.h"

FATTable::FATTable(unsigned int n) {
    this->n = n;
    address = new unsigned short[n];
    printf("%d\n", (int) sizeof(address));
}

void FATTable::writeToFs(FILE *f) {
    fwrite(this->address, n, sizeof(short), f);
}
