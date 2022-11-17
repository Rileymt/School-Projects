#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"

using namespace std;

int main()
{
    string inputFile;
    string outputFile;
    int maxGames;
    
    int menuChoice;


    cout << "How many video games can your library hold?  ";
    cin >> maxGames;
    VideoGameLibrary* myVideoGameLibrary = new VideoGameLibrary(maxGames);

    
    do
    {
        cout << "1. Load video games from file" << endl;
        cout << "2. Save video games to file" << endl;
        cout << "3. Add a video game" << endl;
        cout << "4. Remove a video game" << endl;
        cout << "5. Display Video Games" << endl;
        cout << "6. Remove ALL video games from this Library and end program." << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;
        cin.ignore();
        cout << endl;
        

        switch(menuChoice)
        {
            case 1:
                
                cout << "Enter the name of the file to load: ";
                getline(cin, inputFile);
                myVideoGameLibrary->loadVideoGamesFromFile(&inputFile);
                break;
            case 2:
                
                cout << "Enter the name of the file to save: ";
                getline(cin, outputFile);
                myVideoGameLibrary->saveToFile(&outputFile);
                break;
            case 3:
                
                myVideoGameLibrary->addVideoGameToArray();
                
                break;
            case 4:
                
                myVideoGameLibrary->removeVideoGameFromArray();
                break;
            case 5:
                
                myVideoGameLibrary->displayVideoGames();
                
                break;
            case 6:
                
                delete myVideoGameLibrary;

                break;
            default:
                cout << "Invalid choice.  Please try again." << endl;
                break;
        }

    }while(menuChoice != 6);


}
