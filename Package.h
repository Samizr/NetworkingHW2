//
// Created by Sami on 13-Dec-18.
//

#ifndef NETWORKINGHW2_PACKAGE_H
#define NETWORKINGHW2_PACKAGE_H


class Package {
private:
    double arrivalTime;
    double leaveTime;
    bool active;

public:
    explicit Package(int time);
    void commitPackage(int time);

    double getArrivalTime() const;

    void setLeaveTime(double leaveTime);
};


#endif //NETWORKINGHW2_PACKAGE_H
