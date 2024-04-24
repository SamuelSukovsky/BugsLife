//
// Created by SamuelSukovský on 24/04/2024.
//

#include "Board.h"

using namespace std;

Board::Board(int width, int height) : width{width}, height{height}, bug_vector{}
{

}

void Board::addBug(Bug* bug)
{
    bug_vector.push_back(bug);
}

int Board::getWidth() const
{
    return width;
}

int Board::getHeight() const
{
    return height;
}

void Board::tap()
{
    for (Bug* bug : bug_vector)
    {
        bug -> move();
    }
}

void Board::displayPaths()
{
    for (Bug* bug : bug_vector)
    {
        bug -> displayPath();
    }
}