#include "LinkedList.hpp"
#include <iostream>
#include <ctime>
    int main()
    {
        LinkedList* ll = new LinkedList(); //some change

        std::srand(std::time(nullptr));  
            for (int i = 0; i<20;i++)
            {   
                ll->addEnd(std::rand()%1000);
            }

        ll->display(); 
        std::cout << "-----------------------"<<"\n";
        ll->sort();
        std::cout <<"---------------------"<< "\n";
        ll->display();
        
        delete ll;
    }