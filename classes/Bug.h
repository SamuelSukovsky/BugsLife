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
    string getType();
    int getId();
    int getSize();
    bool getAlive();
    pair<int, int> getPosition();
    string pathToString();

    void setAlive(bool in);

    void eat(Bug* bug);

    virtual string toString() = 0;
    virtual void move() = 0;
    virtual bool isWayBlocked() = 0;

    static bool sizeComparator(Bug* bug1, Bug* bug2);
};


#endif //BUGSLIFE_BUG_H
