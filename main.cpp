#include <iostream>
#include <thread>
#include <conio.h>

#include "classes/Board.h"

int main()
{
    srand(time(nullptr));
    Board board = Board(10, 10);
    bool running = true;
    string input;
    int in;

    while (running)
    {
        cout << "\n1. Initialize Bug Board (load data from file)\n"
                "2. Display all Bugs\n"
                "3. Find a Bug (given an id)\n"
                "4. Tap the Bug Board (causes move all, then fight/eat)\n"
                "5. Display Life History of all Bugs (path taken)\n"
                "6. Display all Cells listing their Bugs\n"
                "7. Run simulation (generates a Tap every second)\n"
                "8. Exit (write Life History of all Bugs to file)\n\n"
                "Enter command:";
        cin >> input;

        try
        {
            in = stoi(input);
        }
        catch(exception e)
        {
            in = 0;
        }
        switch (in)
        {
            case 1 :
            {
                board.initialise("bugs.txt");
                break;
            }
            case 2 :
            {
                board.displayBugs();
                break;
            }
            case 3 :
            {
                cout << "Enter bug id:";
                cin >> input;

                try
                {
                    in = stoi(input);
                    board.findBug(in);
                }
                catch(exception e)
                {
                    cout << "Invalid input" << endl;
                }
                break;
            }
            case 4 :
            {
                board.tap();
                break;
            }
            case 5 :
            {
                board.displayPaths();
                break;
            }
            case 6 :
            {
                board.displayCells();
                break;
            }
            case 7 :
            {
                bool simulating = true;
                while (simulating)
                {
                    if (board.tap() <= 1)
                    {
                        simulating = false;
                    }
                    cout << "tap" << endl;
                    this_thread::sleep_for (chrono::milliseconds (1000));
                    if (kbhit())
                    {
                        simulating = false;
                    }
                }
                break;
            }
            case 8 :
            {
                board.save("bugs_life_history_date_time.out");
                running = false;
                break;
            }
            default:
            {
                cout << "Invalid input" << endl;
            }
        }
    }

    return 0;
}