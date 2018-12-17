//
// Created by Sami on 13-Dec-18.
//

#include "WaitQueue.h"

WaitQueue::WaitQueue(int maxSize) : overallAccepted(0), overallReceived(0), maxSize(maxSize) {}

bool WaitQueue::receivePackage(const Package& package){
    overallReceived++;
    if (packages.size() >= maxSize) {
        return false;
    }
    overallAccepted++;
    packages.push_back(package);
}

Event WaitQueue::generateOutEvent(int currentTime) {
    //TODO
    //return Event(false, 0, nullptr, nullptr);
}

