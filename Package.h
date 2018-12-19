//
// Created by Sami on 13-Dec-18.
//

#ifndef NETWORKINGHW2_PACKAGE_H
#define NETWORKINGHW2_PACKAGE_H


class Package {
private:
    double arrivalTime;
    double leaveTime;
    double treatmentBegin;
    bool active;

public:
    explicit Package(double time);
    void commitPackage(double time);

    double getWaitingTime() const;

    double getServiceTime() const;

    void setTreatmentBegin(double treatmentTime);
};


#endif //NETWORKINGHW2_PACKAGE_H
