#include <iostream>
#include "BootSector.h"
#include "FATTable.h"

using namespace std;

int main() {
    FILE *f;
    f=fopen("/home/ftominc/teste", "w+");
    if(f == NULL){
        cout << "deu zica" << endl;
    }
    FATTable fatTable(10);
    BootSector b(512,1,1,1,1,1,1,1,1,1,1,1);
    cout << sizeof(b.jump_instruction) +
            sizeof(b.OEM_Identifier) +
            sizeof(b.bytes_per_sector) +
            sizeof(b.sectors_per_cluster) +
            sizeof(b.reserved_sectors) +
            sizeof(b.fat_tables) +
            sizeof(b.directory_entries) +
            sizeof(b.total_sectors) +
            sizeof(b.media_descriptor)+
            sizeof(b.sectors_per_fat) +
            sizeof(b.sectors_per_track) +
            sizeof(b.number_of_heads)+
            sizeof(b.hidden_sectors)+
            sizeof(b.large_total_sectors)+
            sizeof(b.padding) << endl;
    cout << sizeof(BootSector) << endl;
    b.WriteToFS(f);
    cout << "Hello, World!" << endl;
    return 0;
}