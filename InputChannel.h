//
// Created by Sami on 17-Dec-18.
//

#ifndef NETWORKINGHW2_INPUTCHANNEL_H
#define NETWORKINGHW2_INPUTCHANNEL_H

#include <vector>
#include "Package.h"
//#include "Event.h"

using std::vector;

class InputChannel {
private:
    vector<double> probabilities;
    double lambda;
public :
    InputChannel();

    explicit InputChannel(const vector<double> &probabilities, double lambda);

    int processPackage(const Package &package);

    double getDistributionVariable();

};


#endif //NETWORKINGHW2_INPUTCHANNEL_H
