#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
using std::string;
using std::cout;

hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	srand (time(0));
	tableSize = size;
	hashArray = new entry*[tableSize];
	for(int i = 0; i < tableSize; i++)
		hashArray[i] = NULL;

		//this needs to be in the constructor, otherwise every user gets the same salt
}
//add the destructor-------------------------------------------------------------------------------------
hashTable::~hashTable()
{
	for(int i = 0; i < tableSize; i++)
	{
		entry *temp = hashArray[i];
		while(temp != NULL)
		{
			entry *temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
	}
	delete [] hashArray;
}

//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

//don't touch this!
string hashTable::generateSalt()
{
	string salt = "";
	
	for(int i = 0; i < tableSize; i++)
		salt = salt + char('!' + (rand() % 93));
	return salt;
}

string hashTable::getSalt(string username)
{
	//return the salt for the given username
	entry *temp = getEntry(username);
	if(temp != NULL)
		return temp->getSalt();
	else
		return "";
}

void hashTable::addEntry(string username, string password, string salt)
{
	//add the new user to the table
	int index = hash(username);
	entry *temp = hashArray[index];
	entry *newEntry = new entry(username, password, salt);
	
	if(temp == NULL)
		hashArray[index] = newEntry;
	else
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newEntry;
	}
}

bool hashTable::validateLogin(string username, string password)
{
	//check if the user's credentials are correct
	entry *temp = getEntry(username);
	if(temp != NULL)
	{
		string salt = temp->getSalt();
		string hash = sha256(password + salt);
		if(hash == temp->getHashedPwd())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool hashTable::removeUser(string username, string password)
{
	//remove the user from the table
	int index = hash(username);
	entry *temp = hashArray[index];
	entry *prev = NULL;
	
	if(temp == NULL)
		return false;
	else
	{
		while(temp != NULL)
		{
			if(temp->getUsername() == username)
			{
				if(prev == NULL)
					hashArray[index] = temp->next;
				else
					prev->next = temp->next;
				delete temp;
				return true;
			}
			prev = temp;
			temp = temp->next;
		}
		return false;
	}
}

hashTable::entry *hashTable::getEntry(string username)
{
	//return the entry for the given username
	int index = hash(username);
	entry *temp = hashArray[index];
	
	if(temp == NULL)
		return NULL;
	else
	{
		while(temp != NULL)
		{
			if(temp->getUsername() == username)
				return temp;
			temp = temp->next;
		}
		return NULL;
	}
}

//entry constructor
hashTable::entry::entry(string username, string password, string salt)
{
	uname = username;
	passHash = sha256(password + salt);
	this->salt = salt;
	next = NULL;
}

//entry get functions
string hashTable::entry::getUsername()
{
	return uname;
}

string hashTable::entry::getSalt()
{
	return salt;
}

string hashTable::entry::getHashedPwd()
{
	return passHash;
}

