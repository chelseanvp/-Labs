#include <iostream>
#include "TASK1.h"
#include "TASK2.h"
#include "TASK3.h"

int main() {
    char isContinue ;
    int choice;
    do {
        std::cout<<"Enter number:"<<std::endl;
        std::cout<<"1. Task1 "<<std::endl;
        std::cout<<"2. Task2 "<<std::endl;
        std::cout<<"3. Task3 "<<std::endl;
        std::cin>>choice;

        switch(choice){
            case 1:
                Task1();
                break;
            case 2:
                Task2();
                break;
            case 3:
                Task3();
                break;
            default:
                std::cout<<"Please enter 1..3"<<std::endl;
        }

        std::cout<<"Do you wont to continue? y-yes"<<std::endl;
        std::cin>>isContinue;
    } while (isContinue == 'y');
    std::cout<<"Good bye!";
    return 0;
}
