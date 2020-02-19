#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

void LinkedList::addFront(int payload)
{
    Node* n = new Node(payload);  //Node n = new Node(payload); in Java

    if(!this->head) //Tests the pointer count of this -> head, boils down to 0 if nothing points here
    {
        this->head = n;
    }
    else //if list has at least one thing in it
    {
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}

int LinkedList::getFront()
{
    return this->head->getPayload(); //pointer, Node that lives at the frond of the list
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

void LinkedList::addEnd(int payload) //assuming there is at least one node
{
    if(!this->head)
    {
        this->addFront(payload);
    }
    else
    {
        Node* n  = new Node(payload);
        Node* currNode = this->head;
        for(int i = 0; i < this->count; i++)
        {
        
            if(i+1<this->count)
            {
                //std::cout << "Loop TIME" << currNode->getPayload() << "\n" ;
                currNode = currNode->getNextNode();
            
            }
            else
            {
                //std::cout << "LAST TIME" <<currNode->getPayload() << "\n" ;
                currNode->setNextNode(n);
            }        
        }   
        count += 1;
    }
   
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
    if(!this->head->getNextNode())
    {
        this->removeFront();
    }
    else
    {
        int returnValue = LinkedList::getEnd();
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
                count-=1;
                return returnValue;
            }       
        }
    }       
}




void LinkedList::addIndex(int payload, int index)
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
        Node* n  = new Node(payload);
        Node* currNode = this->head;
        Node* prevNode;
        for(int i = 0; i< index; i++)
        {
            prevNode = currNode;
            currNode = currNode->getNextNode();   
        }
        //std::cout << "prev Node:" << prevNode->getPayload()<<" CurrNode:" <<currNode->getPayload() << "\n";
        prevNode->setNextNode(n);
        n->setNextNode(currNode);
        count +=1;
    }    
}

int LinkedList::getIndex(int index)
{
    if(index >= count-1)
    {
        return this->getEnd();
    }
    else if (index == 0)
    {
        return this->getFront();
    }
    else
    {
        Node* currNode = this->head;

        for(int i = 0; i< index; i++)
        {  
            if(i<index)
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
    int returnValue = LinkedList::getIndex(index);
    if(index==0)
    {
        this->removeFront();
        return returnValue;
    }
    else if(index==count-1)
    {
        this->removeEnd();
        return returnValue;
    }
    else
    {
    Node* prevNode;
    Node* currNode = this->head;
    Node* nextNode;
    int i = 0;

        while(i<index)
        {
            i+=1;
            prevNode = currNode;
            currNode = currNode->getNextNode();
            nextNode = currNode->getNextNode();
        }
        //std::cout << "RUNNNNUINGINGINGINIGN" << "\n"<<"prev: "<<prevNode->getPayload() <<"curr: " << currNode->getPayload() << "next: " << nextNode->getPayload() <<"\n";
        delete currNode;
        prevNode->setNextNode(nextNode);
        count-=1;
        return returnValue;
    }
}

void LinkedList::sort()
{
    int count3=0;
    Node* currNode = this->head;

    for(int i = 0; i < this->count; i++)        
    {
        //std::cout<<"alert"<<"\n";
        if(currNode->getPayload() > currNode->getNextNode()->getPayload()) //checks if current payload is greater then next payload
        {
            
            Node * otherCurr = this->head;
            int countTwo = 0;
            int testingNum = currNode->getNextNode()->getPayload();
 
            for(int z = 0; z<i; z++)
            {
                
                if(otherCurr->getPayload() >= testingNum)
                {
                    
                    //std::cout<<"count: " <<countTwo<<"\n"<<this->getIndex(countTwo)<<"\n";
                    int temp = this->removeIndex(count3);
                    this->addIndex(testingNum,countTwo);
                    break;

                }
                else
                {
                    
                    otherCurr = otherCurr->getNextNode();
                    countTwo+=1;
                }
                
            }
        }
        else
        {
            currNode = currNode->getNextNode();
        }
        count3+=1;
    }
}
    
void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";

         currNode = currNode->getNextNode();
    }
}

void LinkedList::displayPointers()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode << "\n";
        currNode = currNode->getNextNode();
    }
}