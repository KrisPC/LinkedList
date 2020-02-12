#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

void LinkedList::addFront(int payload)
{
    Node* n = new Node(payload); //Node n = new Node(payload); in Java
    //If list is currently empty
    if(!this->head) //tests the pointer count of this->head (boils down to zero if nothing points here)
                    // Java: this.head == null; 
    {
        this->head = n;
    }
    else //list has at least one thing in it
    {
        n->setNextNode(this->head);
        this->head = n;
    } 
    this->count++;
}

void LinkedList::addEnd(int payload)
{
    Node* n = new Node(payload);
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        if(i+1<this->count)
        {
            currNode = currNode->getNextNode();
        }

        else
        {
            currNode->setNextNode(n);
        }
        
    }
            count += 1;
    }

int LinkedList::getEnd()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        if(i+1<this->count)
        {
            currNode = currNode->getNextNode();
        }

        else
        {
            return currNode->getPayload();
            
        }  
    } 
}

int LinkedList::removeEnd()
{
    int answer = LinkedList::getEnd();
     Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        if(i+2<this->count)
        {
            currNode = currNode->getNextNode();
        }

        else
        {
            currNode->setNextNode(NULL);
            count -= 1;
            return answer; 

        }
        
    }

}

int LinkedList::getFront()
{
    return this->head->getPayload(); 
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}
    
void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        //standard library, needed for printing
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
}