#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Text.h"


using namespace std;

//make a class called VideoGame with a title, developer, publisher, and year
class VideoGame
{
    private:
        
        char* title;
        char* developer;
        char* publisher;
        int year;
        

    public:
        
        VideoGame(char*, char*, char*, int);
        ~VideoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream*);
        char* getVideoGameTitle();
        
};

#endif