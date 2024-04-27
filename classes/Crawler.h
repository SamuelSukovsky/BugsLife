//
// Created by SamuelSukovský on 17/04/2024.
//

#ifndef BUGSLIFE_CRAWLER_H
#define BUGSLIFE_CRAWLER_H

#include <iostream>
#include "Bug.h"

using namespace std;

class Crawler : public Bug
{
public:
    Crawler(int id, int size, pair<int, int> position, DIRECTION dir);

    string toString() override;
    void move() override;
    bool isWayBlocked() override;
};


#endif //BUGSLIFE_CRAWLER_H
