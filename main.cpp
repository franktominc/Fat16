#include <iostream>
#include "BootSector.h"
#include "FATTable.h"
#include "FileEntry.h"
#include "Fat16FileSystem.h"

using namespace std;

void fastFormatter(Fat16FileSystem f){
    f.fastFormatter();
}

void zeroFillFormatter(Fat16FileSystem f){
    f.zeroFillFormatter();
}

int mainMenu(){
    system("clear");

    printf("Main Menu:\n");
    printf("1 - Format the device\n");
    printf("2 - Move file from disk\n");
    printf("3 - Move file to disk\n");
    printf("4 - List Directories\n");

    int i = 0;
    scanf("%d", &i);
    while(i < 1 || i >4){
        printf("Invalid Option!!\n");
        scanf("%d", &i);
    }

    return i;
}

int formatMenu(){
    system("clear");
    printf("Format options:\n");
    printf("1 - Fast\n");
    printf("2 - Zero Fill\n");

    int i;
    scanf("%d", &i);
    while (i < 1 || i > 2){
        printf("Invalid Option!!\n");
        scanf("%d", &i);
    }
    return i;
}

int main() {
    FILE *f;

    f=fopen("/dev/sdc1", "wb+");
    if(f == NULL){
        cout << "deu zica" << endl;
        return 139;
    }
    void (*pf[8])(Fat16FileSystem);
    pf[0] = fastFormatter;
    pf[1] = zeroFillFormatter;
    Fat16FileSystem fs(f);


    fs.zeroFillFormatter();
    int k = mainMenu();
    int n;
    switch(k){
        case 1:
            n = formatMenu();
            pf[n-1](fs);
            break;
        default:
            break;
    }
    return 0;
}