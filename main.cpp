  
#include "LinkedList.hpp"
#include <iostream>

int main()
{
    LinkedList* ll = new LinkedList(); //some change
    ll->addFront(1);
    ll->addFront(2);
    ll->display();
    ll->addEnd(9999);
    ll->display();
    std::cout << ll->getEnd() << "\n";
    std::cout << ll->removeEnd() << "\n"; 
    ll->display();
    delete ll;
}