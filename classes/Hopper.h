//
// Created by SamuelSukovský on 17/04/2024.
//

#ifndef BUGSLIFE_HOPPER_H
#define BUGSLIFE_HOPPER_H

#include <iostream>
#include "Bug.h"

using namespace std;

class Hopper : public Bug
{
private:
    int hopLength;
public:
    Hopper(int id, int size, pair<int, int> position, DIRECTION dir, int hopLength);

    string toString() override;
    void move() override;
    bool isWayBlocked() override;
};


#endif //BUGSLIFE_HOPPER_H
