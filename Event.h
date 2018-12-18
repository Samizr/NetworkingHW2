//
// Created by Sami on 17-Dec-18.
//

#ifndef NETWORKINGHW2_EVENT_H
#define NETWORKINGHW2_EVENT_H

#include "WaitQueue.h"
#include "InputChannel.h"

class Event {
private:
    bool inEvent;
    int time;
    WaitQueue *outQueue;
    InputChannel *inQueue;

public:
    Event(bool inEvent, int time, WaitQueue *outQueue, InputChannel *inQueue);
    bool isInEvent();
    int getTime() const;
    WaitQueue *getOutQueue() const;
    InputChannel *getInQueue() const;

    bool operator<(const Event &rhs) const;

    bool operator>(const Event &rhs) const;

    bool operator<=(const Event &rhs) const;

    bool operator>=(const Event &rhs) const;
};


#endif //NETWORKINGHW2_EVENT_H
