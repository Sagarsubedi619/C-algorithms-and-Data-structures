#ifndef H_Deque
#define H_Deque

#include <iostream>
using namespace std;

template <class T>
class deque
{
    public:
        const deque<T>& operator=(const deque<T>&):
        T front()const;
        T back()const;
        void push_front(const T& assignedElement);
        void push_back(const T& assignedElement);
        void pop_front();
        void pop_back();
        bool empty() const;

        deque(int dequeSize=20);
        deque(const deque<T>& otherQueue);
        ~deque();

    private:
        int maxQueuesize;
        int count;
        int queueFront;
        int queueRear;

        T *first;
    
        T *last;


};

template <class T>
T deque<T>::front() const
{
    return queueRear;

}

template <class T>
T deque<T>::back() const
{
    return queueFront;

}

template <class T>
void deque<T>::push_front(const T& newElement)
{

}
template <class T>
void deque<T>::push_back(const T& newElement)
{

}
template <class T>
void deque<T>::pop_front()
{

}
template <class T>
void deque<T>::pop_back()
{

}
template <class T>
bool deque<T>::empty() const
{
    return (count==0);

}



#endif
