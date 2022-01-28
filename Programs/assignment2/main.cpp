#include <iostream>
#include "deque.h"

int main()
{
    deque<int> dq;
    cout << "Inserting 20 in the front queue...\n";
    dq.push_front(20);
    cout << "Inserting 30 in the back of the queue...\n";
    dq.push_back(30);
    cout << "Inserting 40 in the back of the queue...\n";
    dq.push_back(40);
    cout << "Front element: "
        << dq.front()<< endl;
    cout << "Back element: "
        << dq.back()<< endl;
    cout << "Deleting front element...: "<< endl;
    dq.pop_front();

    cout << "Front element: "
     << dq.front()<< endl;

    cout << "Inserting 50 in the queue...\n";
    dq.push_front(50);

    cout << "Deleting back element...: "<< endl;
    dq.pop_back();

    cout << "Front element: "
    << dq.front()<< endl;

    cout << "Back element: "
    << dq.back()<< endl;
    return 0;
}
