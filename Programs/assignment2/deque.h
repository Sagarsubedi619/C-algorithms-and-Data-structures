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
        //constructor
        deque(const deque<T>& otherQueue);
        //copy constructor
        ~deque();
        //destructor
        const deque<T>& operator=(const deque<T>&);
         //Overload the assignment operator.
        T front();
        //return front element
        T back();
        //return back element
        bool empty() const;
        //check weather the queue is empty
        void  push_front(const T& assignedElement);
        //push elements in front
        void push_back(const T& assignedElement);
        //push elements at back
        void pop_front();
        //delete front element
        void pop_back();
        //delete back element

        
};
template<class T>
bool deque<T>::empty() const
{
return(Size==0);
}

template<class T>
void deque<T>::push_front(const T& assignedElement)
{
    deque_node<T>* newNode=deque_node<T>::getnode(assignedElement);
    if(newNode==NULL){
        cout<<"error";
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

            //assign respective pointers
        }
        Size++;
    }
}

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
            //assign respective pointers
        }
        Size++;
    }

}

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
        if(Front==NULL){Rear=NULL;}
        else{Front->prev=NULL;}
        //reassigning pointers
        free(temp);
        Size--;

    }

}

template<class T>
void deque<T>::pop_back()
{
    if(empty())
    {
        cout<<"Underflow\n";
    }
    else
    {
        deque_node<T>* temp=Rear;
        Rear=Rear->prev;
        if(Rear==NULL){Front=NULL;}
        else{Rear->next=NULL;}
        //reassigning pointers
        free(temp);
        Size--;

    }

}

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

}



#endif

