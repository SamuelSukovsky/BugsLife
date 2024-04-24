//
// Created by SamuelSukovský on 24/04/2024.
//

#include <fstream>
#include <sstream>
#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

Board::Board(int width, int height) : width{width}, height{height}, bug_vector{}
{

}

void Board::initialise(string fileName)
{
    ifstream fin(fileName);
    if (fin)
    {
        while(!fin.eof())
        {
            string input;
            getline(fin, input);
            stringstream line(input);

            getline(line, input, ';');
            string type = input;

            getline(line, input, ';');
            int id = stoi(input);

            pair <int, int> position;
            getline(line, input, ';');
            position.first = stoi(input);
            getline(line, input, ';');
            position.second = stoi(input);

            getline(line, input, ';');
            int direction = stoi(input);

            getline(line, input, ';');
            int size = stoi(input);

            DIRECTION dir;
            switch (direction)
            {
                case 1 :
                    dir = NORTH;
                    break;
                case 2 :
                    dir = EAST;
                    break;
                case 3 :
                    dir = SOUTH;
                    break;
                case 4 :
                    dir = WEST;
                    break;
                default:
                    break;
            }

            if (type == "C")
            {
                Bug* bug = new Crawler(id, size, position, dir);
                this -> addBug(bug);
            }
            else if (type == "H")
            {
                getline(line, input, ';');
                int hopLength = stoi(input);
                Bug* bug = new Hopper(id, size, position, dir, hopLength);
                this -> addBug(bug);
            }
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
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

void Board::displayBugs()
{
    for (Bug* bug : bug_vector)
    {
        bug -> display();
    }
}

void Board::displayPaths()
{
    for (Bug* bug : bug_vector)
    {
        bug -> displayPath();
    }
}