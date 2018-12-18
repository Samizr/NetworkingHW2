//
// Created by Sami on 17-Dec-18.
//

#include "Event.h"
#include <random>

bool Event::isInEvent() {
    return inEvent;
}

Event::Event() : inEvent(true), time(-1), outQueue(nullptr), inQueue(nullptr){
}

Event::Event(bool inEvent, double currentTime, WaitQueue *outQueue, InputChannel *inQueue)
        : inEvent(inEvent), outQueue(outQueue), inQueue(inQueue) {
    std::default_random_engine generator;
    std::exponential_distribution<double> distribution;

    if (inEvent) {
        distribution = std::exponential_distribution<double>(inQueue->getDistributionVariable());
    } else {
        distribution = std::exponential_distribution<double>(outQueue->getDistributionVariable());
    }
    time = currentTime + distribution(generator);
}

double Event::getTime() const {
    return time;
}

WaitQueue *Event::getOutQueue() const {
    return outQueue;
}

InputChannel *Event::getInQueue() const {
    return inQueue;
}

bool Event::operator<(const Event &rhs) const {
    return time < rhs.time;
}

bool Event::operator>(const Event &rhs) const {
    return rhs < *this;
}

bool Event::operator<=(const Event &rhs) const {
    return !(rhs < *this);
}

bool Event::operator>=(const Event &rhs) const {
    return !(*this < rhs);
}

bool Event::operator==(const Event &rhs) const {
    return time == rhs.time;
}

bool Event::operator!=(const Event &rhs) const {
    return !(rhs == *this);
}
