//
// Created by Sami on 17-Dec-18.
//

#ifndef NETWORKINGHW2_INPUTCHANNEL_H
#define NETWORKINGHW2_INPUTCHANNEL_H

#include <vector>
#include "Package.h"
#include "Event.h"

using std::vector;

class InputChannel {
private:
    vector<double> probabilities;

public :
    explicit InputChannel(const vector<double>& probabilities);
    int processPackage(const Package& package);
    //TODO: Event generateInEvent(int currentTime);

};


#endif //NETWORKINGHW2_INPUTCHANNEL_H
