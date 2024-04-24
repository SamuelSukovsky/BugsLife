//
// Created by samik on 17/04/2024.
//

#ifndef BUGSLIFE_CRAWLER_H
#define BUGSLIFE_CRAWLER_H
#include "Bug.h"

using namespace std;
class Crawler : public Bug
{
public:
    Crawler(int id, int size, pair<int, int> position, DIRECTION dir);

    void move() override
    {
        if (alive)
        {
            if (!isWayBlocked())
            {
                switch (dir)
                {
                    case NORTH : {
                        position.second -= 1;
                    }
                    case EAST : {
                        position.first += 1;
                    }
                    case SOUTH : {
                        position.second += 1;
                    }
                    case WEST : {
                        position.first -= 1;
                    }
                }
            }
        }
    }

    bool isWayBlocked() override
    {
        switch (dir)
        {
            case NORTH : {
                return position.second - 1 >= 0;
            }
            case EAST : {
                return position.first + 1 <= 10;
            }
            case SOUTH : {
                return position.second + 1 <= 10;
            }
            case WEST : {
                return position.first - 1 >= 0;
            }
        }
    }
};


#endif //BUGSLIFE_CRAWLER_H
