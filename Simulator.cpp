//
// Created by Sami on 17-Dec-18.
//

#include "Simulator.h"

void Simulator::run() {
    while (1) {
        //Extract min event:
        Event nextEvent = NULL;
        try{
            nextEvent = events.findMin();
        } catch (MinHeap<Event>::Empty){
            return;
        }

        //Extract min event out or in queue:
        if (nextEvent.isInEvent()) {
            //If input event  --> new Package, processPackage, recievePackage, generate new input event
            if (nextEvent.getTime() > T) {
                continue;
            }
            Package newPackage(nextEvent.getTime());
            InputChannel inChannel = *(nextEvent.getInQueue());
            int outChannelNumber = inChannel.processPackage(newPackage);
            WaitQueue outChannel = outputQueues[outChannelNumber];
            outChannel.receivePackage(newPackage);

            //TODO: generate new input event
        } else {
            //If output event --> packages.popPackage, package.commit, generate new input event
            WaitQueue outChannel = *(nextEvent.getOutQueue());

        }


        events.delMin();
        //insert new event to heap.
    }
}

Simulator::Simulator(int T, int N, int M, vector<vector<double>> probabilities, vector<double> lambdas,
                     vector<int> queueSizes, vector<double> mus) : T(T), N(N), M(M), inputQueues(N), outputQueues(M), totalWaitTime(0) {
    for (int i = 0; i < N; i++) {
        inputQueues[i] = InputChannel(probabilities[i], lambdas[i]);
    }
    for (int j = 0; j < M; j++) {
        outputQueues[j] = WaitQueue(queueSizes[j], mus[j]);
    }

}
