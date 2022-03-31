#include <iostream>
using namespace std;
// design the  space for address and data
struct Node
{
   int Data;
   Node* addressOfNextNode;
};
// access
void printList(Node* n)
{
    while (n != NULL) {
        cout <<n->Data << " ";
        n = n->addressOfNextNode;
    }
}

int main(){
//allocate memory 
   Node node1=Node();
   Node node2= Node();
   Node node3= Node();
   Node node4= Node();
//get reference of nextnodes(memory block number)
   Node* node1address=&node1;
   Node* node2address=&node2;
   Node* node3address=&node3;
   Node* node4address=&node4;

  // Assign values
node1.Data=8;
node1.addressOfNextNode=node2address;

node2.Data=9;
node2.addressOfNextNode=node3address;

node3.Data=10;
node3.addressOfNextNode=node4address;

node4.Data=11;
node4.addressOfNextNode=0;

printList(node1address);

    return 0;
}
