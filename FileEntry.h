//
// Created by ftominc on 1/11/16.
//

#ifndef FAT16_FILEENTRY_H
#define FAT16_FILEENTRY_H


#include <stdlib.h>
#include <stdio.h>

class __attribute__((__packed__)) FileEntry {

public:
    unsigned char* filename;
    unsigned char* extension;
    unsigned char type;
    unsigned char reserved;
    unsigned char tenths_of_second;
    unsigned short creation_time;
    unsigned short creation_date;
    unsigned short last_accessed;
    unsigned short high_first_cluster;
    unsigned short last_modification_time;
    unsigned short last_modification_date;
    unsigned short low_first_cluster;
    unsigned int size;

    FileEntry(){
        filename = (unsigned char*)calloc(8, sizeof(char));
        extension = (unsigned char*)calloc(3, sizeof(char));
        type = 0x0;
        reserved = 0x0;
        tenths_of_second = 0x0;
        creation_time = 0x0;
        creation_date = 0x0;
        last_accessed= 0x0;
        high_first_cluster = 0x0;
        last_modification_time = 0x0;
        last_modification_date = 0x0;
        low_first_cluster = 0x0;
        size = 0x0;

        for(int i = 0; i < 8; i++){
            printf("%4d", filename[i]);
        }
        for (int j = 0; j < 3; ++j) {
            printf("%4d", extension[j]);
        }
        printf("%4d", type);
        printf("%4d", reserved);
        printf("%4d", tenths_of_second);
        printf("%4d", creation_time);
        printf("%4d", creation_date);
        printf("%4d", last_accessed);
        printf("%4d", high_first_cluster);
        printf("%4d", last_modification_time);
        printf("%4d", last_modification_date);
        printf("%4d", low_first_cluster);
        printf("%4d\n", size);
    }

    void writeToFs(FILE * F){
        fwrite(filename, 1, 8, F);
        fwrite(extension, 1, 3, F);
        fwrite(&type, 1, 1, F);
        fwrite(&reserved, 1, 1, F);
        fwrite(&tenths_of_second, 1, 1, F);
        fwrite(&creation_time, 2, 1, F);
        fwrite(&creation_date, 2, 1, F);
        fwrite(&last_accessed,2,1, F);
        fwrite(&high_first_cluster,2,1, F);
        fwrite(&last_modification_time,2,1, F);
        fwrite(&last_modification_date, 2, 1, F);
        fwrite(&low_first_cluster, 2,1,F);
        fwrite(&size, sizeof(int), 1, F);

    }
};


#endif //FAT16_FILEENTRY_H
