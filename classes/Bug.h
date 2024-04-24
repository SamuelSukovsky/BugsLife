//
// Created by SamuelSukovský on 10/04/2024.
//

#ifndef BUGSLIFE_BUG_H
#define BUGSLIFE_BUG_H

#include <list>
#include <utility>
#include <string>

using namespace std;
enum DIRECTION {NORTH, SOUTH, EAST, WEST};

class Bug
{
protected:
    Bug(string type, int id, int size, pair<int, int> position, DIRECTION dir);

    string type;
    int id;
    int size;
    bool alive;
    pair<int, int> position;
    DIRECTION dir;

    list<pair<int,int>> path;
public:
    virtual void display() = 0;
    virtual void move() = 0;
    virtual bool isWayBlocked() = 0;
    void displayPath();
};


#endif //BUGSLIFE_BUG_H
