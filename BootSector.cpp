//
// Created by ftominc on 12/30/15.
//

#include "BootSector.h"

void BootSector::WriteToFS(FILE *f) {
    fwrite(this, sizeof(BootSector), 1, f);

}