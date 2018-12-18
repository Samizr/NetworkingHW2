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
    int T, N, M;
    vector<InputChannel> inputQueues;
    vector<WaitQueue> outputQueues;
    MinHeap<Event> events;
public:
    Simulator(int T, int N, int M, vector<vector<double>> probabilities, vector<double> lambdas, vector<int> queueSizes,
              vector<double> mus);

    void run();

};


#endif //NETWORKINGHW2_SIMULATOR_H


