//
// Created by franktominc on 18/01/16.
//

#include "filler.h"

void filler::writeToFs(FILE *a) {
    fwrite(this->myVec, sizeof(char),512,a);
}
