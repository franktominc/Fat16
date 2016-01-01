//
// Created by ftominc on 12/30/15.
//

#ifndef FAT16_BOOTSECTOR_H
#define FAT16_BOOTSECTOR_H


#include <stdio.h>
#include <string.h>

class __attribute__((__packed__)) BootSector {
public:
    unsigned char jump_instruction[3];
    char OEM_Identifier[8];
    unsigned short bytes_per_sector;
    unsigned char sectors_per_cluster;
    unsigned short reserved_sectors;
    unsigned char fat_tables;
    unsigned short directory_entries;
    unsigned short total_sectors;
    unsigned char media_descriptor;
    unsigned short sectors_per_fat;
    unsigned short sectors_per_track;
    unsigned short number_of_heads;
    unsigned int hidden_sectors;
    unsigned int large_total_sectors;
    unsigned char padding[476]{0};


    BootSector(unsigned short bytes_per_sector,
               unsigned char sectors_per_cluster,
               unsigned short reserved_sectors,
               unsigned char fat_tables,
               unsigned short directory_entries,
               unsigned short total_sectors,
               unsigned char media_descriptor,
               unsigned short sectors_per_fat,
               unsigned short sectors_per_track,
               unsigned short number_of_heads,
               unsigned int hidden_sectors,
               unsigned int large_total_sectors)
            : bytes_per_sector(bytes_per_sector),
              sectors_per_cluster(sectors_per_cluster),
              reserved_sectors(reserved_sectors),
              fat_tables(fat_tables),
              directory_entries(directory_entries),
              total_sectors(total_sectors),
              media_descriptor(media_descriptor),
              sectors_per_fat(sectors_per_fat),
              sectors_per_track(sectors_per_track),
              number_of_heads(number_of_heads),
              hidden_sectors(hidden_sectors),
              large_total_sectors(large_total_sectors) {
        jump_instruction[0] = 0xEB;
        jump_instruction[1] = 0x3C;
        jump_instruction[2] = 0x90;
        sprintf(OEM_Identifier,"mkdosfs");

        padding[510-36] = 0X55;
        padding[511-36] = 0XAA;
    }
    //void WriteToFS(FILE* f);
};


#endif //FAT16_BOOTSECTOR_H
