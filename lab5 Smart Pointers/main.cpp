#include<iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
using namespace std;
int main(int argv, char **args){
    char choice = 'y';
    int condition;
    std::cout<<"1 - Task1"<<std::endl;
    std::cout<<"2 - Task2"<<std::endl;
    std::cout<<"3 - Task3"<<std::endl;

    do{
        std::cin>>condition;
        switch (condition) {
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
                Task1();
                break;
        }

        std::cout<<std::endl<<"Do you wont to continue? y-yes: ";
        std::cin>>choice;
    }while(choice == 'y');
    std::cout<<"Good bye!";
    return 0;
}