//
// Created by Sami on 17-Dec-18.
//

#include "Event.h"
#include <random>

bool Event::isInEvent() {
    return inEvent;
}

Event::Event() : inEvent(true), time(-1), outQueue(nullptr), inQueue(nullptr) {
}

Event::Event(bool inEvent, double currentTime, WaitQueue *outQueue, InputChannel *inQueue,
             std::default_random_engine &generator)
        : inEvent(inEvent), outQueue(outQueue), inQueue(inQueue) {
//    std::random_device generator;
    double addition;
    if (inEvent) {
        std::exponential_distribution<double> distribution(inQueue->getDistributionVariable());
        this->outQueue = nullptr;
        addition = distribution(generator);
    } else {
        std::exponential_distribution<double> distribution(outQueue->getDistributionVariable());
        this->inQueue = nullptr;
        addition = distribution(generator);
    }
    time = currentTime + addition;
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

//CHANGED FROM < to > TO TRANSFORM MAX_HEAP TO MIN_HEAP
bool Event::operator<(const Event &rhs) const {
    return time > rhs.time;
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
