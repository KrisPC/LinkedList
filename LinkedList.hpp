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
    void addAtIndex(int index, int payload); // adds a new node to the list that will ultimately be at the given index 
    int getIndex(int index);//returns the payload at the given index in the list
    int removeIndex(int index); //returns the payload at the given index and removes the node in the list (make sure you decrement count)
    void display();
    
};
#endif /* LinkedList_hpp */