//
// Created by SamuelSukovský on 10/04/2024.
//

#include "Bug.h"

#include <utility>

using namespace std;

Bug::Bug(string type, int id, int size, pair<int, int> position, DIRECTION dir) : type{std::move(type)}, id{id}, size{size}, alive{true}, position{::move(position)}, dir{dir}, path{}
{
    path.push_back(position);
}

string Bug::getType()
{
    return type;
}

int Bug::getId()
{
    return id;
}

int Bug::getSize()
{
    return size;
}

bool Bug::getAlive()
{
    return alive;
}

pair<int, int> Bug::getPosition()
{
    return position;
}


void Bug::setAlive(bool in)
{
    alive = in;
}


void Bug::eat(Bug* other)
{
    size += other -> getSize();
    other -> setAlive(false);
}


string Bug::pathToString()
{
    string ret = to_string(id) + " " + type + " ";
    for (pair<int, int> pos : path)
    {
        ret += "(" + to_string(pos.first) + "," + to_string(pos.second) + ") ";
    }
    if (alive)
        ret += "Alive\n";
    else
        ret += "Dead\n";
    return ret;
}

bool Bug::sizeComparator(Bug* bug1, Bug* bug2)
{
    return bug1 -> getSize() > bug2 -> getSize();
}