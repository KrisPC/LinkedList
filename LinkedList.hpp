#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"

class LinkedList 
{
private:
    Node* head; //Front of the list
    int count; //Actual value 
    
public:
    LinkedList();
    void addFront(int payload);
    int getFront();
    int removeFront();
    //3 methods below
    void addEnd(int payload);//Adds a new node to the end of the payload
    int getEnd(); //Returns the end of the list and removes it permanently from the list (make sure you decrement count)
    int removeEnd(); //Returns the end of the list and gets rid of it permanently 
    void display();
    
};
#endif /* LinkedList_hpp */