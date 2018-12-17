//
// Created by Sami on 17-Dec-18.
//

#ifndef NETWORKINGHW2_SIMULATOR_H
#define NETWORKINGHW2_SIMULATOR_H

#include <vector>
#include "WaitQueue.h"

using std::vector;

class Simulator {
private:
    vector<WaitQueue> outputQueues;
    vector<float> input;
};


#endif //NETWORKINGHW2_SIMULATOR_H
