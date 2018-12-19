//
// Created by Sami on 13-Dec-18.
//

#include "Package.h"

void Package::commitPackage(double time) {
    leaveTime = time;
    active = false;
}

Package::Package(double time) : arrivalTime(time), treatmentBegin(-1), leaveTime(-1), active(true) {

}

double Package::getWaitingTime() const {
    return leaveTime - arrivalTime;
}

double Package::getServiceTime() const {
    return leaveTime - treatmentBegin;
}

void Package::setTreatmentBegin(double treatmentTime) {
    treatmentBegin = treatmentTime;
}
