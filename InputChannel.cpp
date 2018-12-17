//
// Created by Sami on 17-Dec-18.
//

#include <cassert>
#include "InputChannel.h"
#include <ctime>
#include <cstdlib>

static double randomizeFraction();

int InputChannel::processPackage(const Package& package) {
    double randomNumber = randomizeFraction();
    double sum = 0;
    int counter = 0;
    for (double num : probabilities) {
        sum += num;
        if (randomNumber < sum) {
            return counter;
        } else {
            counter++;
        }
    }
    assert(false);
}

InputChannel::InputChannel(const vector<double>& probabilities) : probabilities(probabilities) { }


//STATIC FUNCTIONS:
static double randomizeFraction() {
    srand(time(NULL));
    int nums[7];
    double randNum = 0;
    for (int i = 0; i < 7; i++) {
        randNum += rand() % 10;
        randNum *= 10;
    }
}