//
// Created by SamuelSukovský on 10/04/2024.
//

#include "Bug.h"

#include <utility>
#include <iostream>

using namespace std;

Bug::Bug(int id, int size, pair<int, int> position, DIRECTION dir) : id{id}, size{size}, alive{true}, position{::move(position)}, dir{dir}, path{}
{

}

void Bug::displayPath()
{
    for (pair<int, int> pos : path)
    {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;
}