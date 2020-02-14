  
#include "LinkedList.hpp"
#include <iostream>

int main()
{
    LinkedList* ll = new LinkedList(); //some change
    ll->addFront(5);
    ll->addFront(4);
    ll->addFront(3);
    ll->addFront(2);
    ll->addFront(1);
    ll->display();
    std::cout <<"\n" << ll->removeIndex(0) <<"\n" << "\n";

    ll->display();
    //ll->addAtIndex(1, 9999); 
    //ll->display();
    delete ll;
}