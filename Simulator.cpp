//
// Created by Sami on 17-Dec-18.
//

#include "Simulator.h"

void Simulator::run() {
    while (!events.isEmpty()) {
        //Extract min event:
        Event event = events.findMin();
        double time = event.getTime();

        //Extract min event out or in queue:
        if (event.isInEvent()) {
            //If input event  --> new Package, processPackage, recievePackage, generate new input event
            if (time > T) {
                continue;
            }
            assert(event.getOutQueue() == nullptr);
            Package newPackage(time);
            InputChannel *inQueue = event.getInQueue();
            int outChannelNumber = inQueue->processPackage(newPackage);
            outputQueues[outChannelNumber].receivePackage(newPackage);
        } else {
            //If output event --> packages.popPackage, package.commit, generate new output event
            assert(event.getOutQueue() == nullptr);
            WaitQueue *outQueue = event.getOutQueue();
            if (outQueue->getPackages().empty())
                continue;
            outQueue->popPackage(time); //todo: use func output
        }

        Event newEvent(event.isInEvent(), time, event.getOutQueue(), event.getInQueue());
        events.delMin();
        events.insert(newEvent);
    }
}

Simulator::Simulator(int T, int N, int M, vector<vector<double>> probabilities, vector<double> lambdas,
                     vector<int> queueSizes, vector<double> mus) : T(T), N(N), M(M), inputQueues(N), outputQueues(M),
                                                                   totalWaitTime(0) {
    //INITIATES QUEUES AND FILLS UP N+M NEW EVENTS.
    for (int i = 0; i < N; i++) {
        inputQueues[i] = InputChannel(probabilities[i], lambdas[i]);
        events.insert(Event(true, 0, nullptr, &inputQueues[i]));
    }
    for (int j = 0; j < M; j++) {
        outputQueues[j] = WaitQueue(queueSizes[j], mus[j]);
        events.insert(Event(false, 0, &outputQueues[j], nullptr));
    }
    //TODO: Shouldn't we start inserting out events as soon as something is inserted?
    //TODO: If performance withstands, okay, if not choose above option.
    //TODO: Note that according to this you should implement: if queue has no input, there should be no out events.
}
