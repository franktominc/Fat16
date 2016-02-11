//
// Created by franktominc on 18/01/16.
//

#ifndef FAT16_FILLER_H
#define FAT16_FILLER_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class filler {
public:
    unsigned char* myVec = (unsigned char *)calloc(512, sizeof(char));

    void writeToFs(FILE * a);

    filler(){
        for (int i = 0; i < 512; ++i) {
            if(i%10 == 0)
                printf("\n");
            printf("%4d", myVec[i]);
        }


    }
};


#endif //FAT16_FILLER_H
