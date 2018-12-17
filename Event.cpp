//
// Created by Sami on 17-Dec-18.
//

#include "Event.h"

bool Event::isInEvent() {
    return inEvent;
}

Event::Event(bool inEvent, int time, WaitQueue *outQueue, InputChannel *inQueue) : inEvent(inEvent), time(time),
                                                                                   outQueue(outQueue),
                                                                                   inQueue(inQueue) {}

int Event::getTime() const {
    return time;
}

WaitQueue *Event::getOutQueue() const {
    return outQueue;
}

InputChannel *Event::getInQueue() const {
    return inQueue;
}
