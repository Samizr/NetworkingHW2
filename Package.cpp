//
// Created by Sami on 13-Dec-18.
//

#include "Package.h"

void Package::commitPackage(int time) {
    leaveTime = time;
    active = false;
}

Package::Package(int time) {
    arrivalTime = time;
    leaveTime = -1;
    active = true;
}
