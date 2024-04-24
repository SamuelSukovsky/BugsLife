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

    void display() override
    {
        cout << id << " " << type << " (" << position.first << "," << position.second << ") " << size << " " << hopLength << " ";
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
                    position.second -= hopLength;
                    break;
                }
                case EAST :
                {
                    position.first += hopLength;
                    break;
                }
                case SOUTH :
                {
                    position.second += hopLength;
                    break;
                }
                case WEST :
                {
                    position.first -= hopLength;
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
                return position.second - hopLength < 0;
            }
            case EAST :
            {
                return position.first + hopLength >= 10;
            }
            case SOUTH :
            {
                return position.second + hopLength >= 10;
            }
            case WEST :
            {
                return position.first - hopLength < 0;
            }
        }
    }
};


#endif //BUGSLIFE_HOPPER_H
