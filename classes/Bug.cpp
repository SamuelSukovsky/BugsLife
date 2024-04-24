//
// Created by SamuelSukovský on 10/04/2024.
//

#include "Bug.h"

#include <utility>
#include <iostream>

using namespace std;

Bug::Bug(string type, int id, int size, pair<int, int> position, DIRECTION dir) : type{std::move(type)}, id{id}, size{size}, alive{true}, position{::move(position)}, dir{dir}, path{}
{
    path.push_back(position);
}

void Bug::displayPath()
{
    cout << id << " " << type << " ";
    for (pair<int, int> pos : path)
    {
        cout << "(" << pos.first << "," << pos.second << ") ";
    }
    cout << endl;
}