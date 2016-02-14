    //
    // Created by franktominc on 18/01/16.
    //

    #include "Fat16FileSystem.h"
    #include "filler.h"
    #include <iostream>

    using namespace std;



        void Fat16FileSystem::zeroFillFormatter() {
            BootSector b(512,128,1,1,2048,0,0xf8,128,32,64,2048,4194304);
            FATTable f(b.sectors_per_fat);
            FileEntry fe;
            filler fi;

            //memset(&fi, 0, 512);
            b.WriteToFS(file);
            cout << "Writing the fillers" << endl;
            for (int j = 0; j < (b.bytes_per_sector - 512)/512; j++) {
                fi.writeToFs(file);

            }
            cout << (b.bytes_per_sector - 512)/512 << " fillers was written" << endl;

            f.writeToFs(file);

            cout << "Writing " << b.directory_entries << " directory entries to FS" << endl;

            for (int i = 0; i < b.directory_entries; i++) {
                fe.writeToFs(file);
            }


            cout << "Writing " << b.large_total_sectors << " fillers to FS";

            for (long k = 0; k < b.large_total_sectors; k++) {
                fi.writeToFs(file);
                //printf("%s\n", n);
            }

        }

    void Fat16FileSystem::fastFormatter() {
        BootSector b(512,128,1,1,2048,0,0xf8,128,32,64,2048,4194304);
        FATTable f(b.sectors_per_fat);
        FileEntry fe;
        filler fi;


        //memset(&fi, 0, 512);
        b.WriteToFS(file);
        cout << "Writing the fillers" << endl;
        for (int j = 0; j < (b.bytes_per_sector - 512)/512; j++) {
            fi.writeToFs(file);

        }
        cout << (b.bytes_per_sector - 512)/512 << " fillers was written" << endl;

        f.writeToFs(file);

        cout << "Writing " << b.directory_entries << " directory entries to FS" << endl;

        for (int i = 0; i < b.directory_entries; i++) {
            fe.writeToFs(file);
        }

    }
