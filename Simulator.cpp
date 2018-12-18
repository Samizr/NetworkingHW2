//
// Created by Sami on 17-Dec-18.
//

#include "Simulator.h"

void Simulator::run() {
    //Extract min event:

    //Extract min event out or in queue:

    //If input event  --> new Package, processPackage, recievePackage, generate new input event

    //If output event --> packages.popPackage, package.commit, generate new input event

    //insert new event to heap.

}

Simulator::Simulator(int T, int N, int M, vector<vector<double>> probabilities, vector<double> lambdas,
                     vector<int> queueSizes, vector<double> mus) : T(T), N(N), M(M) {

}
