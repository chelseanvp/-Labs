#include<iostream>
#include <memory>
#include "Task1.h"


void printArray(const int *ptr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

void Task1() {
    int arraySize = 7;
    std::unique_ptr<int[]> ptr1 = std::make_unique<int[]>(arraySize);
    for (int i = 0; i < arraySize; i++) {
        ptr1[i] = rand() % 10;
    }

    std::cout << "Array before:" << std::endl;
    printArray(ptr1.get(), arraySize);

    int key;
    std::cout<<"Deleting for key: "<<std::endl;
    std::cin>>key;

    std::unique_ptr<int[]> tempPtr = std::make_unique<int[]>(arraySize);

    int N = 0;
    for(int i = 0; i<arraySize;i++){
        if (ptr1[i] != key ){
            tempPtr[N] = ptr1[i];
            N++;
        }

    }
    arraySize = N;

    ptr1 = std::make_unique<int[]>(arraySize);
    for(int i = 0; i<arraySize;i++){
            ptr1[i] = tempPtr[i];
    }
    std::cout<<"Array after: "<<std::endl;
    printArray(ptr1.get(),arraySize);


}






