#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "VideoGame.h"




using namespace std;

class VideoGameLibrary
{
    private: 
        int numGames;
        int maxGames;
        VideoGame** videoGameArray;

    public:
        VideoGameLibrary(int);
        ~VideoGameLibrary();

        void loadVideoGamesFromFile(string*);
        void addVideoGameToArray();
        void removeVideoGameFromArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void resizeVideoGameArray();
        void saveToFile(string*);
};





#endif