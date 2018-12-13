//
// Created by Sami on 13-Dec-18.
//

#ifndef NETWORKINGHW2_PACKAGE_H
#define NETWORKINGHW2_PACKAGE_H


class Package {
private:
    int arrivalTime;
    int leaveTime;
    bool active;

public:
    explicit Package(int time);
    void commitPackage(int time);
};


#endif //NETWORKINGHW2_PACKAGE_H
