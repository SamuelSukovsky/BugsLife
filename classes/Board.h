//
// Created by SamuelSukovský on 24/04/2024.
//

#ifndef BUGSLIFE_BOARD_H
#define BUGSLIFE_BOARD_H

#include <vector>
#include <iostream>
#include "Bug.h"

using namespace std;

class Board
{
private:
    int width;
    int height;
    vector<Bug*> bug_vector;
public:
    Board(int width, int height);

    void addBug(Bug* bug);
    int getWidth() const;
    int getHeight() const;
    void tap();
    void displayPaths();
};



#endif //BUGSLIFE_BOARD_H
