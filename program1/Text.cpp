#include "Text.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include "VideoGame.h"
#include "VideoGameLibrary.h"



Text::Text(char* temp)
{	
	//dynamically allocate memory for the char
	temp = new char[strlen(temp) + 1];
	strcpy(temp, temp);
	textArray = temp;

}


Text::~Text()
{
	cout << "\nRELEASING MEMORY FOR THIS Text object:  ";
	delete [] &textArray;
}

void Text::displayText()
{
	cout << textArray;
}

const char* Text::getText() const
{
	return textArray;
}

int Text::getLength() const
{
	return textLength;
}