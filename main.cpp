#include <iostream>
#include <fstream>
#include <sstream>

#include "classes/Board.h"
#include "classes/Bug.h"
#include "classes/Crawler.h"
#include "classes/Hopper.h"

int main()
{
    srand(time(nullptr));
    Board board = Board(10, 10);

    ifstream fin("bugs.txt");
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
                board.addBug(bug);
            }
            else if (type == "H")
            {
                getline(line, input, ';');
                int hopLength = stoi(input);
                Bug* bug = new Hopper(id, size, position, dir, hopLength);
                board.addBug(bug);
            }
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }


    for (int i = 0; i < 15; i++)
    {
        board.tap();
    }
    board.displayPaths();

    return 0;
}