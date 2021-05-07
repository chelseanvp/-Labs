#include <iostream>
#include "TASK2.h"
#include "UserClass.h"


void Task2(){
    int value;
    UserClass list1(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_front(0);
    list1.printList();

    std::cout<<"Remove element"<<std::endl;
    std::cout<<"Enter value: ";
    std::cin>>value;
    list1.remove(value);
    list1.printList();

    UserClass list2;
    list2.push_back(8);
    list2.push_back(7);

    std::cout<<"Remove element"<<std::endl;
    list1.printList();
    std::cout<<"Enter value:"<<std::endl;
    std::cin>>value;
    int n;
    std::cout<<"Enter n:"<<std::endl;
    std::cin>>n;

    list1.remove(value,n);
    list1.merge(list2);
    list1.printList();
    list2.printList();


}

