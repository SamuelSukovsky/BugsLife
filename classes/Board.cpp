//
// Created by SamuelSukovský on 24/04/2024.
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include "Board.h"
#include "Crawler.h"
#include "Drifter.h"
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
            else if (type == "D")
            {
                getline(line, input, ';');
                int driftLength = stoi(input);
                Bug* bug = new Drifter(id, size, position, dir, driftLength);
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

void Board::save(string fileName)
{
    ofstream fout(fileName);
    if (fout)
    {
        for (Bug* bug : bug_vector)
        {
            fout << bug -> pathToString();
        }
        fout.close();
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


int Board::tap()
{
    int count = 0;
    for (Bug* bug : bug_vector)
    {
        bug -> move();
    }

    vector<Bug*> bugList;
    for (Bug* bug : bug_vector)
    {
        bugList.push_back(bug);
    }

    sort(bugList.begin(), bugList.end(), Bug::sizeComparator);
    for (Bug* bug1 : bugList)
    {
        if (bug1 -> getAlive())
        {
            count++;
            for (Bug *bug2: bugList)
            {
                if (bug2->getAlive())
                {
                    if (bug1->getPosition() == bug2->getPosition() &&
                        bug1 != bug2)
                    {
                        if (bug1->getSize() > bug2->getSize())
                        {
                            bug1->eat(bug2);
                        }
                        else if (bug1->getSize() < bug2->getSize())
                        {
                            bug2->eat(bug1);
                        }
                        else
                        {
                            switch (rand() % 2)
                            {
                                case 0 :
                                    bug1->eat(bug2);
                                case 1 :
                                    bug2->eat(bug1);
                            }
                        }
                    }
                }
            }
        }
    }

    return count;
}

void Board::displayBugs()
{
    for (Bug* bug : bug_vector)
    {
        cout << bug -> toString();
    }
}

void Board::findBug(int id)
{
    for (Bug* bug : bug_vector)
    {
        if(bug -> getId() == id)
        {
            cout << bug -> toString();
            return;
        }
    }

    cout << "Bug id " << id << " not found." << endl;
}

void Board::displayPaths()
{
    for (Bug* bug : bug_vector)
    {
        cout << bug -> pathToString();
    }
}

void Board::displayCells()
{
    pair<int, int> cell;

    list<Bug*> bugList;
    for (Bug* bug : bug_vector)
    {
        bugList.push_back(bug);
    }
    bool empty;

    for (int x = 0; x < width; x++)
    {
        cell.first = x;
        for (int y = 0; y < height; y++)
        {
            cell.second = y;
            cout << "(" << cell.first << "," << cell.second << "): ";
            empty = true;
            if (!bugList.empty())
            {
                for (Bug* bug : bugList)
                {
                    if (bug->getPosition() == cell)
                    {
                        cout << bug -> getType() << " " << bug -> getId() << endl;
                        bugList.remove(bug);
                        empty = false;
                        break;
                    }
                }
                if (empty)
                {
                    cout << "Empty" << endl;
                }
            }
        }
    }
}