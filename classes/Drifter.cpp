//
// Created by SamuelSukovský on 27/04/2024.
//

#include "Drifter.h"

Drifter::Drifter(int id, int size, pair<int, int> position, DIRECTION dir, int driftLength) : driftLength{driftLength}, step{1}, Bug("Drifter ", id, size, position, dir)
{

}

string Drifter::toString()
{
    string ret = to_string(id) + " " + type + " (" + to_string(position.first) + "," + to_string(position.second) + ") " + to_string(size) + " " + to_string(step) + "/" + to_string(driftLength) + " ";
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

void Drifter::move()
{
    if (alive)
    {
        step++;
        if (step > driftLength)
        {
            dir = DIRECTION((dir + 3 + rand() % 3) % 4);
            step = 1;
        }
        while(isWayBlocked())
        {
            dir = DIRECTION(rand() % 4);
        }
        switch (dir)
        {
            case NORTH :
                position.second -= 1;
                break;
            case EAST :
                position.first += 1;
                break;
            case SOUTH :
                position.second += 1;
                break;
            case WEST :
                position.first -= 1;
                break;
        }
        path.push_back(position);
    }
}

bool Drifter::isWayBlocked()
{
    switch (dir)
    {
        case NORTH :
            return position.second - 1 < 0;
        case EAST :
            return position.first + 1 >= 10;
        case SOUTH :
            return position.second + 1 >= 10;
        case WEST :
            return position.first - 1 < 0;
    }
}