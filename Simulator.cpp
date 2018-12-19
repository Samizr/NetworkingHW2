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

        if (overAllInput == 420)
            int debug;
        //Extract min event out or in queue:
        if (event.isInEvent()) {
            //If input event  --> new Package, processPackage, recievePackage, generate new input event
            if (time > T) {
                continue;
            }
            //DEBUG BEGIN:
            overAll++;
            overAllInput++;
//            std::cout << "Input Event number: " << overAllInput << ", out of overall: " << overAll << std::endl;
            //DEBUG END!
            assert(event.getOutQueue() == nullptr);
            Package newPackage(time);
            InputChannel *inQueue = event.getInQueue();
            int outChannelNumber = inQueue->processPackage(newPackage, generator);
            outputQueues[outChannelNumber].receivePackage(newPackage);
        } else if (!event.getOutQueue()->getPackages().empty()){
            //If output event --> packages.popPackage, package.commit, generate new output event
            //DEBUG BEGIN:
            overAll++;
            overAllOutput++;
//            std::cout << "Output Event number: " << overAllOutput << ", out of overall: " << overAll << std::endl;
            //DEBUG END!
            assert(event.getInQueue() == nullptr);
            WaitQueue *outQueue = event.getOutQueue();
            Package outPackage = outQueue->popPackage(time);
            totalServiceTime += outPackage.getWaitingTime();
            totalWaitTime += outPackage.getServiceTime();
            outQueue->getPackages().begin()->setTreatmentBegin(time);
            //TODO: first top, or first top after free queue, will fail?
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
                                                                   outputQueues(M), totalWaitTime(0), generator(rd()) {
    //INITIATES QUEUES AND FILLS UP N+M NEW EVENTS.
    for (int i = 0; i < N; i++) {
        inputQueues[i] = (InputChannel(probabilities[i], lambdas[i]));
        eventsHeap.emplace_back(Event(true, 0, nullptr, &inputQueues[i]));
    }
    for (int j = 0; j < M; j++) {
        outputQueues[j] = (WaitQueue(queueSizes[j], mus[j]));
        eventsHeap.emplace_back(Event(false, 0, &outputQueues[j], nullptr));
    }
    std::make_heap(eventsHeap.begin(), eventsHeap.end());
    //TODO: Shouldn't we start inserting out events as soon as something is inserted?
    //TODO: If performance withstands, okay, if not choose above option.
    //TODO: Note that according to this you should implement: if queue has no input, there should be no out events.
    //DEBUG PARAMETERS:
    overAll = 0;
    overAllInput = 0;
    overAllOutput = 0;
}

void Simulator::printResults() {
    using std::cout;
    using std::endl;
    long int numReceived = calculateReceived();
    long int numAccepted = calculateAccepted();
    //PRINT Y:
    cout << numReceived << " ";
    //PRINT Yi:
    for (auto &outQ : outputQueues) {
        cout << outQ.getOverallReceived() << " ";
    }
    //PRINT X:
    cout << numReceived - numAccepted << " ";
    //PRINT Xi:
    for (auto &outQ : outputQueues) {
        cout << outQ.getOverallReceived() - outQ.getOverallAccepted() << " ";
    }
    //PRINT T'
    cout << currentT << " ";

    //PRINT AVG WAIT TIME:
    cout << totalWaitTime/(double)numAccepted << " ";

    //PRINT AVG SERVICE TIME:
    cout << totalServiceTime/(double)numAccepted << endl;


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


