//
// Created by Sami on 13-Dec-18.
//


#ifndef NETWORKINGHW2_WAITQUEUE_H
#define NETWORKINGHW2_WAITQUEUE_H

#include "Package.h"
//#include "Event.h"
#include <vector>

using std::vector;

class WaitQueue {
private:
    int overallReceived;
    int overallAccepted;
    vector<Package> packages;
    int maxSize;
    double mu;

public:
    WaitQueue();

    WaitQueue(int maxSize, double mu);

    bool receivePackage(const Package &package);

    double popPackage(double popTime);

    void incOverallReceived();

    int getMaxSize() const;

    const vector<Package> &getPackages() const;

    void incOverallAccepted();

    double getDistributionVariable();
};


#endif //NETWORKINGHW2_WAITQUEUE_H
