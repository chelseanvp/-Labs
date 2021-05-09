#include<iostream>
#include <memory>
#include "Task2.h"


void printArray(const std::unique_ptr<std::unique_ptr<int[]>[]> &ptr, const int N, const int M)
{
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cout << ptr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void Task2(){
    int N = 4;
    int M = 5;

    std::unique_ptr<std::unique_ptr<int[]>[]> ptr1(std::make_unique<std::unique_ptr<int[]>[]>(N));
    for (int i = 0; i < N; i++){
        ptr1[i] = std::make_unique<int[]>(M);
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            ptr1[i][j] = 1;
        }
    }

    std::cout<<"Array before: "<<std::endl;
    printArray(ptr1,N,M);

    N++;
    std::unique_ptr<std::unique_ptr<int[]>[]> tempPtr(std::make_unique<std::unique_ptr<int[]>[]>(N));
    for (int i = 0; i < N; i++){
        tempPtr[i] = std::make_unique<int[]>(M);
    }
    for (int i = 0; i < M; i++){
        tempPtr[N-1][i] = 2;
    }

    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < M; j++){
            tempPtr[i][j] = ptr1[i][j];
        }
    }
    ptr1 = move(tempPtr);
    std::cout<<"Array after: "<<std::endl;
    printArray(ptr1,N,M);

}