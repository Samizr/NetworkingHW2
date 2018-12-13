//
// Created by Sami on 13-Dec-18.
//

#include "Package.h"
#include <vector>
#ifndef NETWORKINGHW2_WAITQUEUE_H
#define NETWORKINGHW2_WAITQUEUE_H


class WaitQueue {
public:
    int overallReceived;
    int overallAccepted;
    vector<Package> packages;

};


#endif //NETWORKINGHW2_WAITQUEUE_H
