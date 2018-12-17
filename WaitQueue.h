//
// Created by Sami on 13-Dec-18.
//


#ifndef NETWORKINGHW2_WAITQUEUE_H
#define NETWORKINGHW2_WAITQUEUE_H

#include "Package.h"
#include "Event.h"
#include <vector>

using std::vector;

class WaitQueue {
private:
    int overallReceived;
    int overallAccepted;
    vector<Package> packages;
    int maxSize;

public:
    WaitQueue(int maxSize);
    bool receivePackage(const Package& package);
    Event generateOutEvent(int currentTime);
};


#endif //NETWORKINGHW2_WAITQUEUE_H
