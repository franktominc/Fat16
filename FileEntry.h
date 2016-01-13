//
// Created by ftominc on 1/11/16.
//

#ifndef FAT16_FILEENTRY_H
#define FAT16_FILEENTRY_H


class __attribute__((__packed__)) FileEntry {
    unsigned char filename[8];
    unsigned char extension[3];
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
};


#endif //FAT16_FILEENTRY_H
