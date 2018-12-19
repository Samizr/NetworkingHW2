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

using std::vector;

class Simulator {
private:
    double T, currentT;
    int N, M;
    vector<InputChannel> inputQueues;
    vector<WaitQueue> outputQueues;
    vector<Event> eventsHeap;
    double totalWaitTime;
    double totalServiceTime;
    std::random_device rd;
    std::default_random_engine generator;
    long int calculateAccepted();
    long int calculateReceived();

public:
    Simulator(double T, int N, int M, vector<vector<double>> probabilities, vector<double> lambdas, vector<int> queueSizes,
              vector<double> mus);

    void run();

    void printResults();

};


#endif //NETWORKINGHW2_SIMULATOR_H


