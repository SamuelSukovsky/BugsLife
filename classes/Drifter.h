//
// Created by SamuelSukovský on 27/04/2024.
//

#ifndef BUGSLIFE_DRIFTER_H
#define BUGSLIFE_DRIFTER_H

#include <iostream>
#include "Bug.h"

using namespace std;

class Drifter : public Bug
{
private:
    int driftLength;
    int step;
public:
    Drifter(int id, int size, pair<int, int> position, DIRECTION dir, int driftLength);

    string toString() override;
    void move() override;
    bool isWayBlocked() override;
};


#endif //BUGSLIFE_DRIFTER_H
