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
            currNode = currNode->getNextNode(); ///returns true when currNode has a next Node
        }

        else
        {
            currNode->setNextNode(n); //currNode now points to the end of our list (the last Node)
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

void LinkedList::addAtIndex(int index, int payload)
{
    if(index == 0)
    {
        this->addFront(payload);
    }
    else if (index >= count)
    {
        this->addEnd(payload);
    }

    else
    {
        Node* n = new Node(payload); //2
        Node* currNode = this->head; // 1
        Node* prevNode; //points at 1, currently nothing, but first points at 1 to make sure it fills it
        for(int i = 0; i < index; i++) //runs through list, goes to length of index
        {
            prevNode = currNode; //2 points to 1
            currNode = currNode->getNextNode(); 
        }
        std::cout <<"Prev Node:" << prevNode->getPayload()<<" Curr Node:" << currNode->getPayload() << "\n";
        prevNode->setNextNode(n);
        n->setNextNode(currNode);
        count +=1;
    }

    
}

int LinkedList::getIndex(int index)
{
    if(index >= count - 1)
    {
        return this->getEnd();
    }

    else if(index == 0)
    {
        return this->getFront();
    }

    else
    {
        Node* currNode = this->head;

        for(int i = 0; i < index; i++)
        {
            if(i< index)
            {
                currNode = currNode->getNextNode();
            }
            else 
            {
                return currNode->getPayload();
            }
        }

    }
    
}

int LinkedList::removeIndex(int index)
{
    int answer = LinkedList::getIndex(index);
    if(index==0)
    {
        this->removeFront();
        return answer;
    }

    else if(index == count - 1)
    {
        this-removeEnd();
        return answer;
    }

    Node* currNode = this->head;
    Node* prevNode;
    Node* nextNode;
    int i = 0;

    while(i<index)
    {
            i += 1;
            prevNode = currNode;
            currNode = currNode->getNextNode();
            nextNode = currNode->getNextNode();

    }
            delete currNode;
            prevNode->setNextNode(nextNode);
            count -= 1;
            return answer;
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