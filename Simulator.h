//
// Created by Sami on 17-Dec-18.
//

#ifndef NETWORKINGHW2_SIMULATOR_H
#define NETWORKINGHW2_SIMULATOR_H

#include <vector>
#include "WaitQueue.h"
#include "InputChannel.h"
#include <algorithm>
#include "Event.h"
#include "MinHeap.h"

using std::vector;

class Simulator {
private:
    int N, M, T;
    vector<WaitQueue> outputQueues;
    vector<InputChannel> inputQueues;
    MinHeap<Event> events;
public:
    Simulator(int N, int M, int T, vector<vector<double>> allProbabilities);
    void run();
};


#endif //NETWORKINGHW2_SIMULATOR_H
