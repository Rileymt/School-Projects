#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "VideoGame.h"
#include "Text.h"
#include "VideoGameLibrary.h"

using namespace std;

//constructor for the VideoGame class
VideoGame::VideoGame(char* title, char* developer, char* publisher, int year)
{
    //set the title to the title
    this->title = title;
    //set the developer to the developer
    this->developer = developer;
    //set the publisher to the publisher
    this->publisher = publisher;
    //set the year to the year
    this->year = year;

}

//destructor for the VideoGame class
VideoGame::~VideoGame()
{
    
    cout << "\nRELEASING MEMORY FOR THIS VideoGame object:  ";
    delete [] &title;
    delete [] &developer;
    delete [] &publisher;
    delete [] &year;
  

}

//function that prints the details of a video game to the screen
void VideoGame::printVideoGameDetails()
{
    
    //print the title, developer, publisher, and year of the video game to the screen
    cout << right << setw(30) << "Game Title: " << left << setw(30) << title << endl;
    cout << right << setw(30) << "Developer: " << left << setw(30) << developer << endl;
    cout << right << setw(30) << "Publisher: " << left << setw(30) << publisher << endl;
    cout << right << setw(30) << "Year Realeased: " << left << setw(30) << year << endl;

}
//function that prints the details of a video game to a file
void VideoGame::printVideoGameDetailsToFile(ofstream* outFile)
{
    //print the title, developer, publisher, and year of the video game to the file
    *outFile << "Title: " << title << endl;
    *outFile << "Developer: " << developer << endl;
    *outFile << "Publisher: " << publisher << endl;
    *outFile << "Year: " << year << endl;
}

//accessor function for the title
char* VideoGame::getVideoGameTitle()
{
    //return the title
    return title;
}
