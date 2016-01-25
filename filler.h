//
// Created by franktominc on 18/01/16.
//

#ifndef FAT16_FILLER_H
#define FAT16_FILLER_H


#include <stdio.h>
#include <string.h>

class filler {
public:
    unsigned char* myVec;

    void writeToFs(FILE * a);

    filler(){
        myVec = new unsigned char[512];
        memset(myVec, 0,512);
    }
};


#endif //FAT16_FILLER_H
