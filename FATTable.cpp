//
// Created by ftominc on 1/3/16.
//

#include <stdlib.h>
#include "FATTable.h"

FATTable::FATTable(unsigned int n) {
    this->n = n;
    printf("calloc was called\n");
    address = (unsigned short*) calloc(n*512, sizeof(short));
    printf("done\n");
    address[0] = 0xfff8;
    address[1] = 0xfff8;

}

void FATTable::writeToFs(FILE *f) {
    fwrite(this->address, sizeof(short),n, f);
}
