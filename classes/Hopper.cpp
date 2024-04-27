//
// Created by SamuelSukovský on 17/04/2024.
//

#include "Hopper.h"

Hopper::Hopper(int id, int size, pair<int, int> position, DIRECTION dir, int hopLength) : hopLength{hopLength}, Bug("Hopper  ", id, size, position, dir)
{

}

string Hopper::toString()
{
    string ret = to_string(id) + " " + type + " (" + to_string(position.first) + "," + to_string(position.second) + ") " + to_string(size) + " " + to_string(hopLength) + " ";
    switch (dir)
    {
        case NORTH:
            ret += "North";
            break;
        case EAST:
            ret += "East";
            break;
        case SOUTH:
            ret += "South";
            break;
        case WEST:
            ret += "West";
            break;
    }
    if (alive)
        ret += " Alive\n";
    else
        ret += " Dead\n";
    return ret;
}

void Hopper::move()
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
                position.second -= hopLength;
                break;
            case EAST :
                position.first += hopLength;
                break;
            case SOUTH :
                position.second += hopLength;
                break;
            case WEST :
                position.first -= hopLength;
                break;
        }
        path.push_back(position);
    }
}

bool Hopper::isWayBlocked()
{
    switch (dir)
    {
        case NORTH :
            return position.second - hopLength < 0;
        case EAST :
            return position.first + hopLength >= 10;
        case SOUTH :
            return position.second + hopLength >= 10;
        case WEST :
            return position.first - hopLength < 0;
    }
}