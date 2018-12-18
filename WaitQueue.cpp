//
// Created by Sami on 13-Dec-18.
//

#include "WaitQueue.h"
#include <random>

WaitQueue::WaitQueue(int maxSize, double mu) : overallAccepted(0), overallReceived(0), maxSize(maxSize), mu(mu) {}

bool WaitQueue::receivePackage(const Package &package) {
    overallReceived++;
    if (packages.size() >= maxSize) {
        return false;
    }
    overallAccepted++;
    packages.push_back(package);
}

double WaitQueue::popPackage(double popTime) {
    Package &current = packages.front();
    double arrival = current.getArrivalTime();
    current.commitPackage(popTime);
    packages.erase(packages.begin());
    return popTime - arrival;
}

const vector<Package> &WaitQueue::getPackages() const {
    return packages;
}

int WaitQueue::getMaxSize() const {
    return maxSize;
}

double WaitQueue::getDistributionVariable() {
    return mu;
}

WaitQueue::WaitQueue() : overallAccepted(-1), overallReceived(-1), maxSize(-1), mu(-1){

}

int WaitQueue::getOverallReceived() const {
    return overallReceived;
}

void WaitQueue::setOverallReceived(int overallReceived) {
    WaitQueue::overallReceived = overallReceived;
}

int WaitQueue::getOverallAccepted() const {
    return overallAccepted;
}

void WaitQueue::setOverallAccepted(int overallAccepted) {
    WaitQueue::overallAccepted = overallAccepted;
}


