//
// Created by Sami on 13-Dec-18.
//

#include "WaitQueue.h"
#include <random>
#include <cassert>

WaitQueue::WaitQueue(int maxSize, double mu) : overallAccepted(0), overallReceived(0), maxSize(maxSize), mu(mu) {}

bool WaitQueue::receivePackage(const Package &package, double receiveTime) {
    overallReceived++;
    if (packages.size() >= maxSize) {
        return false;
    }
    overallAccepted++;
    packages.push_back(package);
    assert(!packages.empty());
    if (packages.size() == 1)
        packages.front().setTreatmentBegin(receiveTime);
}

Package WaitQueue::popPackage(double popTime) {
    Package current = packages.front();
    current.commitPackage(popTime);
    packages.erase(packages.begin());
    assert(current.getServiceTime() > 0);
    return current;
}

vector<Package> &WaitQueue::getPackages() {
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


