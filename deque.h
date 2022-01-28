#ifndef H_Deque
#define H_Deque
#include <iostream>
#include "deque_node.h"
using namespace std;




template <class T>
class deque
{
    deque_node<T>* Front;
    deque_node<T>* Rear;
    int Size;
    public:
        deque(){
            Front=NULL;
            Rear=NULL;
            Size=0;
            }
        const deque<T>& operator=(const deque<T>&);
        T front();
        T back();
        void  push_front(const T& assignedElement);
        void push_back(const T& assignedElement);
        void pop_front();
        void pop_back();
        bool empty() const;
};
template<class T>
bool deque<T>::empty() const
{
    
}

template<class T>
void deque<T>::push_front(const T& assignedElement)
{
    deque_node<T>* newNode=deque_node<T>::getnode(assignedElement);
    if(newNode==NULL){
        cout<<"overflow\n";
    }
    else
    {
        if(Front==NULL)
        {
            Rear=newNode;
            Front=newNode;
        }
        else
        {
            newNode->next=Front;
            Front->prev=newNode;
            Front=newNode;
        }
        Size++;
    }
};

template<class T>
void deque<T>::push_back(const T& assignedElement)
{
     deque_node<T>* newNode=deque_node<T>::getnode(assignedElement);
     if(newNode==NULL){
        cout<<"overflow\n";
    }
    else
    {
        if(Rear==NULL)
        {
            Front=newNode;
            Rear=newNode;
        }
        else
        {
            newNode->prev=Rear;
            Rear->next=newNode;
            Rear=newNode;
        }
        Size++;
    }

};

template<class T>
void deque<T>::pop_front()
{
    if(empty())
    {
        cout<<"Underflow\n";
    }
    else
    {
        deque_node<T>* temp=Front;
        Front=Front->next;
        if(Front==NULL){Rear==NULL;}
        else{Front->prev=NULL;}
        free(temp);
        Size--;

    }

};

template<class T>
void deque<T>::pop_back()
{
    if(empty())
    {
        cout<<"Underflow\n";
    }
    else
    {
        deque_node<T>* temp=Front;
        Rear=Rear->prev;
        if(Rear==NULL){Front==NULL;}
        else{Rear->next=NULL;}
        free(temp);
        Size--;

    }

};

template<class T>
T deque<T>::front()
{
    if(empty()){return -1;}
    else{return Front->data;}

}

template<class T>
T deque<T>::back()
{
    if(empty()){return -1;}
    else{return Rear->data;}

};



#endif
