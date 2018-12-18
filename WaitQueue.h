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

    int getMaxSize() const;

    int getOverallReceived() const;

    void setOverallReceived(int overallReceived);

    int getOverallAccepted() const;

    void setOverallAccepted(int overallAccepted);

    const vector<Package> &getPackages() const;

    double getDistributionVariable();
};


#endif //NETWORKINGHW2_WAITQUEUE_H
