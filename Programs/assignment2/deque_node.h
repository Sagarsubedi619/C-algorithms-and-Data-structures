#ifndef H_deque_node
#define H_deque_node

#include <iostream>
using namespace std;

template <class T>
struct deque_node
{
    T data; //datafield
     struct deque_node *next; //next pointer
     struct deque_node *prev; //previous pointer


     static deque_node* getnode(const T& data)
     {
         deque_node* newNode=(deque_node*)malloc(sizeof(deque_node));
         newNode->data=data;
         newNode->prev=newNode->next=NULL;
         return newNode;

         //get new node in the heap
     }
    
    
};

#endif

