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

    void display() override
    {
        cout << id << " " << type << " (" << position.first << "," << position.second << ") " << size << " ";
        switch (dir)
        {
            case NORTH:
                cout << "North";
                break;
            case EAST:
                cout << "East";
                break;
            case SOUTH:
                cout << "South";
                break;
            case WEST:
                cout << "West";
                break;
        }
        if (alive)
            cout << " Alive" << endl;
        else
            cout << " Dead" << endl;
    }

    void move() override
    {
        if (alive)
        {
            while(isWayBlocked())
            {
                dir = DIRECTION(rand() % 4);
            }
            switch (dir)
            {
                case NORTH :
                {
                    position.second -= 1;
                    break;
                }
                case EAST :
                {
                    position.first += 1;
                    break;
                }
                case SOUTH :
                {
                    position.second += 1;
                    break;
                }
                case WEST :
                {
                    position.first -= 1;
                    break;
                }

            }
            path.push_back(position);
        }
    }

    bool isWayBlocked() override
    {
        switch (dir)
        {
            case NORTH :
            {
                return position.second - 1 < 0;
            }
            case EAST :
            {
                return position.first + 1 >= 10;
            }
            case SOUTH :
            {
                return position.second + 1 >= 10;
            }
            case WEST :
            {
                return position.first - 1 < 0;
            }
        }
    }
};


#endif //BUGSLIFE_CRAWLER_H
