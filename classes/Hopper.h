//
// Created by samik on 17/04/2024.
//

#ifndef BUGSLIFE_HOPPER_H
#define BUGSLIFE_HOPPER_H
#include "Bug.h"

using namespace std;
class Hopper : public Bug
{
private:
    int hopLength;
public:
    Hopper(int id, int size, pair<int, int> position, DIRECTION dir, int hopLength);

    void move() override
    {
        if (alive)
        {
            if (!isWayBlocked())
            {
                switch (dir)
                {
                    case NORTH :
                    {
                        position.second -= hopLength;
                    }
                    case EAST :
                    {
                        position.first += hopLength;
                    }
                    case SOUTH :
                    {
                        position.second += hopLength;
                    }
                    case WEST :
                    {
                        position.first -= hopLength;
                    }
                }
            }
        }
    }

    bool isWayBlocked() override
    {
        switch (dir)
        {
            case NORTH :
            {
                return position.second - hopLength >= 0;
            }
            case EAST :
            {
                return position.first + hopLength <= 10;
            }
            case SOUTH :
            {
                return position.second + hopLength <= 10;
            }
            case WEST :
            {
                return position.first - hopLength >= 0;
            }
        }
    }
};


#endif //BUGSLIFE_HOPPER_H
