#include <iostream>
#include "BootSector.h"
#include "FATTable.h"
#include "FileEntry.h"
#include "Fat16FileSystem.h"

using namespace std;

int main() {
    FILE *f;
    f=fopen("/dev/sdb1", "wb+");
    if(f == NULL){
        cout << "deu zica" << endl;
    }
    Fat16FileSystem fs(f);
    fs.writeToFS();


    return 0;
}