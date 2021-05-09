#include<iostream>
#include <memory>
#include "Task3.h"

void printArray1(const std::unique_ptr<std::unique_ptr<int[]>[]> &ptr, const int N, const int M){
    std::cout<<"Array: "<<std::endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cout << ptr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void Task3(){
    int N = 6;
    int M = 6;

    std::unique_ptr<std::unique_ptr<int[]>[]> ptr1(std::make_unique<std::unique_ptr<int[]>[]>(N));
    for (int i = 0; i < N; i++){
        ptr1[i] = std::make_unique<int[]>(M);
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            ptr1[i][j] = rand() % 50 + 10;
        }
    }

    printArray1(ptr1,N,M);

    int temp = ptr1[1][N-1];
    std::cout<<"Elements below the side diagonal:"<<std::endl;
    for (int i = 1; i < N; ++i) {
        for (int j = N - i; j < N; ++j) {
            if(ptr1[i][j] > temp){
                temp = ptr1[i][j];
            }
            std::cout << ptr1[i][j] << " ";
        }
    }
    std::cout<<std::endl<<"Max Element:"<<temp<<std::endl;


}