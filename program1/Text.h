#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "VideoGame.h"


using namespace std;

class Text
{
	private:
		const char* textArray;
		int textLength;
		
	public:
		
		Text(char*);
		~Text();	
		void displayText();	
		const char* getText() const;
		int getLength() const;
			
	
}; 
#endif