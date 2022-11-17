//Riley Tilson
//CSC 1310-002
//10/13/2022
#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include "County.h"



using namespace std;

template <class T> class List
{
    public:
        struct listNode
        {
            T value;
            listNode* next;
            listNode* prev;
        };
        listNode *head;
        listNode *tail;
        //constructor
        List()
        {
            head = NULL;
            tail = NULL;
        }
        //destructor
        ~List()
        {
            listNode *nodePtr;
            listNode *nextNode;
            nodePtr = head;
            while(nodePtr != NULL)
            {
                nextNode = nodePtr->next;
                delete nodePtr;
                nodePtr = nextNode;
            }
        }
        //public print function
        void print()
        {
            listNode *nodePtr;
            nodePtr = head;
            print(nodePtr);
        }
        //append function
        void append(T value)
        {
            listNode *newNode;
            listNode *nodePtr;
            newNode = new listNode;
            newNode->value = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            if(!head)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                nodePtr = head;
                while(nodePtr->next)
                {
                    nodePtr = nodePtr->next;
                }
                nodePtr->next = newNode;
                newNode->prev = nodePtr;
                tail = newNode;
            }
        }
        //public mergesort function
        void mergesort()
        {
            head = mergeSort(head, tail);
        }
    private: 
        //private print function
        void print(listNode* nodePtr)
        {
            if(nodePtr != NULL)
            {
                print(nodePtr->next);
                cout << *nodePtr->value << endl;
            }
        }
        //private mergesort function
        listNode* mergeSort(listNode* next, listNode* prev)
        {
            listNode* head = next;
            listNode* tail = prev;
            if(head == tail)
            {
                return head;
            }
            listNode* middle = split(head, tail);
            listNode* nextMiddle = middle->next;
            middle->next = NULL;
            nextMiddle->prev = NULL;
            listNode* left = mergeSort(head, middle);
            listNode* right = mergeSort(nextMiddle, tail);
            listNode* sortedList = merge(left, right);
            return sortedList;
        }
        //merge function
        listNode* merge(listNode* next, listNode* prev)
        {
            //sort by population
            listNode* head = next;
            listNode* tail = prev;
            listNode* sortedList = NULL;
            if(head == NULL)
            {
                return tail;
            }
            else if(tail == NULL)
            {
                return head;
            }
            if(*head->value < *tail->value)
            {
                sortedList = head;
                sortedList->next = merge(head->next, tail);
                sortedList->next->prev = sortedList;
                sortedList->prev = NULL;
            }
            else
            {
                sortedList = tail;
                sortedList->next = merge(head, tail->next);
                sortedList->next->prev = sortedList;
                sortedList->prev = NULL;
            }
            
            return sortedList;

        }
        //split function
        listNode* split(listNode* next, listNode* prev)
        {
            //find the middle of the list
            listNode* slow = next;
            listNode* fast = prev;
            while(fast != NULL)
            {
                fast = fast->next;
                if(fast != NULL)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            //return the middle
            return slow;

        }




        
};




        



#endif