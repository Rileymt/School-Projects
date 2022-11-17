#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"

using namespace std;

//make a constructor that takes in an integer
VideoGameLibrary::VideoGameLibrary(int maxGames)
{
    //set the number of games to 0
    numGames = 0;
    //set the max number of games to the integer passed to the constructor
    this->maxGames = maxGames;
    //make a new array of pointers to VideoGame objects
    videoGameArray = new VideoGame*[maxGames];
}

//make a destructor
VideoGameLibrary::~VideoGameLibrary()
{
    //release the dynamically allocated array of pointers to VideoGame objects
    cout << "\nRELEASING MEMORY FOR THIS VideoGameLibrary object:  ";
    for(int i = 0; i < maxGames; i++)
    {
        if(videoGameArray[i] != NULL)
        {
            delete videoGameArray[i];
        }
    }
    delete [] videoGameArray;
}


//function that loads video games from a file into the array
void VideoGameLibrary::loadVideoGamesFromFile(string *fileName)
{
    //open the file
    ifstream inFile;
    inFile.open(*fileName);
    //check to see if the file opened successfully
    if(inFile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
        
    }
    //read the file
    while(!inFile.eof())
    {
        
        //if numgames is greater than or equal to maxgames then call the resize function
        if(numGames >= maxGames)
        {
            resizeVideoGameArray();
            cout << "Resizing VideoGameArray from " << maxGames-1 << " to " << (maxGames-1)*2 << endl;
        }
        
        char* title = new char[100];
        char* developer = new char[100];
        char* publisher = new char[100];
        int year;
        inFile.getline(title, 100);
        inFile.getline(developer, 100);
        inFile.getline(publisher, 100);
        inFile >> year;
        inFile.ignore();
        videoGameArray[numGames] = new VideoGame(title, developer, publisher, year);
        cout << title << " was added successfully" << endl;
        numGames++;

    }
    cout << numGames << " video games were read from the file and added to your VideoGame library." << endl << endl;
    //close the file
    inFile.close();
}

//function that will manually add a video game to the array
void VideoGameLibrary::addVideoGameToArray()
{
    //check to see if the array is full
    if(numGames >= maxGames)
    {
        //if it is, resize the array
        resizeVideoGameArray();
        cout << "Resizing VideoGameArray from " << maxGames-1 << " to " << (maxGames-1)*2 << endl;
    }
    //get the title, developer, publisher, and year of the video game from the user
    
    char* title = new char[100];
    char* developer = new char[100];
    char* publisher = new char[100];
    int year;
    
    cout << "Video Game TITLE: ";
    cin.getline(title, 100);
    cout << endl << "Video Game DEVELOPER: ";
    cin.getline(developer, 100);
    cout << endl << "Video Game PUBLISHER: ";
    cin.getline(publisher, 100);
    cout << endl << "Video Game YEAR: ";
    cin >> year;
    cin.ignore();
    cout << endl << endl;
    //make a new VideoGame object and add it to the array
    videoGameArray[numGames] = new VideoGame(title, developer, publisher, year);
    numGames++;



    
}


//remove a video game from the array
void VideoGameLibrary::removeVideoGameFromArray()
{
    //check to see if the array is empty
    if(numGames == 0)
    {
        //if it is, print an error message
        cout << "Error:  The array is empty" << endl;
    }
    //display the titles of the video games in the array and ask which video game the user would like to remove baised on number
    else
    {
        cout << "Choose from the following video games to remove:" << endl << endl;
        for(int i = 0; i < numGames; i++)
        {
            cout << i+1 << ". " << videoGameArray[i]->getVideoGameTitle() << endl;
        }
        cout << "Choose a video game to remove between 1 and " << numGames << ": ";
        int choice;
        cin >> choice;
        cin.ignore();
        
        //use the videogame destructor to delete the video game
        videoGameArray[choice-1]->~VideoGame();
        

        //shift the array to fill the gap
        for(int i = choice-1; i < numGames-1; i++)
        {
            videoGameArray[i] = videoGameArray[i+1];
        }
        //decrement the number of games
        numGames--;
    }
    
}


// display the title, developer, publisher, and year of each video game in the array
void VideoGameLibrary::displayVideoGames()
{
    //check to see if the array is empty
    if(numGames == 0)
    {
        //if it is, print an error message
        cout << "Error:  The array is empty" << endl;
    }
    //if the array is not empty
    else
    {
        //print the title, developer, publisher, and year of each video game in the array
        for(int i = 0; i < numGames; i++)
        {
            cout << "                             ----------Video Game " << i+1 << "----------" << endl;
            videoGameArray[i]->printVideoGameDetails();
            cout << endl << endl;
        }
    }
}

//function that will display the video game titles in the array
void VideoGameLibrary::displayVideoGameTitles()
{
    //display the title of each video game in the array using the getVideoGameTitle() function
    for(int i = 0; i < numGames; i++)
    {
        cout << "Video Game " << i+1 << ":  ";
        videoGameArray[i]->getVideoGameTitle();
        cout << endl;
    }

    
}

//print the video games to a file
void VideoGameLibrary::saveToFile(string* fileName)
{
    //open the file
    ofstream outputFile;
    outputFile.open(fileName->c_str());


    //check to see if the file opened
    if(!outputFile)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    // print the game information to the file
    for(int i = 0; i < numGames; i++)
    {
        //use printVideoGameDetailsToFile to print the video game details to the file
        videoGameArray[i]->printVideoGameDetailsToFile(&outputFile);

    }
    
    cout << "All video games in your library have been printed to " << *fileName << endl;
    //close the file
    outputFile.close();
}




void VideoGameLibrary::resizeVideoGameArray()
{
    //make a new array that is twice as big as the old array
    VideoGame** tempArray = new VideoGame*[maxGames * 2];
    //copy the old array into the new array
    for(int i = 0; i < maxGames; i++)
    {
        tempArray[i] = videoGameArray[i];
    }
    //delete the old array
    delete [] videoGameArray;
    //set the old array to the new array
    videoGameArray = tempArray;
    //double the max number of games
    maxGames = maxGames * 2;
}



