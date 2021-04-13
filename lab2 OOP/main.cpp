#include <iostream>
#include <windows.h>
#include "HeadingOfClassQueue.h"
#include "RealizaciyaOfClassQueue.h"
#include "UserClass.h"

void printMenu(){
    std::cout << "Menu: " << std::endl;
    std::cout << "1. Add element to the queue" << std::endl;
    std::cout << "2. Remove element from the queue" << std::endl;
    std::cout << "3. Is queue empty?" << std::endl;
    std::cout << "4. Print queue"<<std::endl;
    std::cout << "5. Fold two queues"<<std::endl;
    std::cout << "6. queue1 = queue2 "<<std::endl;
    std::cout << "7. Exit"<<std::endl;
}


int main() {

    setlocale(LC_ALL, "rus");
    bool exit = false;
    int operation;
    int value;
    int sizeArray;

    User object;
    Queue <int,User>obj;

    std::cout<<"Object size: "<<obj.objectSize(object)<<std::endl;
    printMenu();

    Queue <int,User>obj1;
    Queue<int,User>obj2;


    do {

        //std::cout<<"| 0 - Open Menu |"<<std::endl;
        std::cin >>operation;

        switch (operation) {
            case 0:
                printMenu();
                break;
            case 1:
                std::cout<<"Enter value:";
                std::cin>>value;
                obj.push(value);
                break;
            case 2:
                --obj;
                break;
            case 3:
                if(obj.getArraySize() == 0){
                    std::cout <<"Queue is empty!"<<std::endl;
                }else{
                    std::cout <<"Queue isn't empty!"<<std::endl;
                }
                std:: cout<< "Queue size:"<<obj.getArraySize()<<std::endl;
                break;
            case 4:
                obj.print();
                break;
            case 5:
                std::cout<<"First queue size: ";
                std::cin>>sizeArray;
                for(int i = 0;i<sizeArray;i++){
                    std::cout<<"Value:";
                    std::cin>>value;
                    obj1.push(value);
                }
                std::cout<<"Second queue size: ";
                std::cin>>sizeArray;
                for(int i = 0;i<sizeArray;i++){
                    std::cout<<"Value:";
                    std::cin>>value;
                    obj2.push(value);
                }
                obj = obj1+obj2;
                std::cout<<"Done! "<<std::endl;
                break;
            case 6:
                std::cout<<"first queue:"<<std::endl;
                obj1.print();
                std::cout<<"second queue:"<<std::endl;
                obj2.print();
                obj1 = obj2;
                std::cout<<"first queue after 'queue1 = queue2':"<<std::endl;
                obj1.print();
                break;
            case 7:
                exit = true;
        }

    }while(!exit);


    std::cout<<"Good bye!"<<std::endl;
    return 0;
}
