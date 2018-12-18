//
// Created by Sami on 17-Dec-18.
//

#include "Simulator.h"
#include <iostream>
#include <cassert>

static long int calculateReceived();

void Simulator::run() {
    while (!eventsHeap.empty()) {
        //Extract min event:
        std::pop_heap(eventsHeap.begin(), eventsHeap.end());
        Event event = eventsHeap.back();
        eventsHeap.pop_back();
        double time = event.getTime();
        currentT = time;

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
            assert(event.getInQueue() == nullptr);
            WaitQueue *outQueue = event.getOutQueue();
            if (outQueue->getPackages().empty())
                continue;
            outQueue->popPackage(time); //todo: use func output
        }
        if (time < T) {
            Event newEvent(event.isInEvent(), time, event.getOutQueue(), event.getInQueue());
            eventsHeap.push_back(newEvent);
            std::push_heap(eventsHeap.begin(), eventsHeap.end());
        }
    }
}

Simulator::Simulator(double T, int N, int M, vector<vector<double>> probabilities, vector<double> lambdas,
                     vector<int> queueSizes, vector<double> mus) : T(T), currentT(0), N(N), M(M), inputQueues(N),
                                                                   outputQueues(M), totalWaitTime(0) {
    //INITIATES QUEUES AND FILLS UP N+M NEW EVENTS.
    for (int i = 0; i < N; i++) {
        inputQueues[i] = InputChannel(probabilities[i], lambdas[i]);
        eventsHeap.push_back(Event(true, 0, nullptr, &inputQueues[i]));
    }
    for (int j = 0; j < M; j++) {
        outputQueues[j] = WaitQueue(queueSizes[j], mus[j]);
        eventsHeap.push_back(Event(false, 0, &outputQueues[j], nullptr));
    }
    std::make_heap(eventsHeap.begin(), eventsHeap.end());
    //TODO: Shouldn't we start inserting out events as soon as something is inserted?
    //TODO: If performance withstands, okay, if not choose above option.
    //TODO: Note that according to this you should implement: if queue has no input, there should be no out events.
}

void Simulator::printResults() {
    using std::cout;
    long int numReceived = calculateReceived();
    long int numAccepted = calculateAccepted();
    cout << numAccepted << " ";
    for (auto &outQ : outputQueues) {
        cout << outQ.getOverallAccepted() << " ";
    }
    cout << numReceived << " ";
    for (auto &outQ : outputQueues) {
        cout << outQ.getOverallReceived() << " ";
    }
    cout << currentT << " ";


}

long int Simulator::calculateAccepted() {
    long int sum = 0;
    for (auto &outQ : outputQueues) {
        sum += outQ.getOverallAccepted();
    }
    return sum;
}

long int Simulator::calculateReceived() {
    long int sum = 0;
    for (auto &outQ : outputQueues) {
        sum += outQ.getOverallReceived();
    }
    return sum;
}


