//
// Created by Sami on 17-Dec-18.
//

#include <cassert>
#include "InputChannel.h"
#include <ctime>
#include <random>
#include <cstdlib>

//static double randomizeFraction();

int InputChannel::processPackage(const Package &package, std::default_random_engine& generator) {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double randomNumber = distribution(generator);
    double sum = 0;
    int counter = 0;
    for (double num : probabilities) {
        sum += num;
        if (randomNumber <= sum) {
            return counter;
        } else {
            counter++;
        }
    }
    assert(false);
}

InputChannel::InputChannel(const vector<double> &probabilities, double lambda) : probabilities(probabilities),
                                                                                 lambda(lambda){
}

double InputChannel::getDistributionVariable() {
    return lambda;
}

InputChannel::InputChannel() : lambda(-1){

}


//STATIC FUNCTIONS:
//static double randomizeFraction() {
//    return distribution(generator);
//}

//PREVIOUS GENERATOR:
//    srand(time(NULL));
//    int nums[7];
//    double randNum = 0;
//    for (int i = 0; i < 7; i++) {
//        randNum += rand() % 10;
//        randNum *= 10;
//    }
