// Created by Nikolay on 11.04.2021.
#pragma once
#ifndef OOTP_LAB4_REALIZACIYAOFCLASSQUEUE_H
#define OOTP_LAB4_REALIZACIYAOFCLASSQUEUE_H
#include<iostream>
#include "HeadingOfClassQueue.h"

template<class T , class T2>
Queue<T,T2>:: Queue(){
    arraySize = 0;
    ptr = new T [arraySize];
}

template<class T,class T2>
Queue<T,T2>::Queue(const Queue &other) { //конструктор копирования
    this->arraySize = other.arraySize;
    this->ptr = new T[other.arraySize];
    for(int i =0; i<arraySize;i++) {
        this->ptr[i] = other.ptr[i];
    }

}
template<class T , class T2>
void Queue<T,T2>::operator=(const Queue &other) {  // operator =
    this->arraySize = other.arraySize;
    if(this->ptr != nullptr){
        delete[] this->ptr;
    }

    this->ptr = new T[other.arraySize];
    for(int i =0; i<arraySize;i++) {
        this->ptr[i] = other.ptr[i];
    }

}

template<class T , class T2>
Queue<T,T2> Queue<T,T2>::operator+(Queue object) {
    Queue temp;
    temp.arraySize = this->arraySize +object.arraySize;
    temp.ptr = new T[temp.arraySize];

    for(int i=0;i< this->arraySize;i++){
        temp.ptr[i] = this->ptr[i];
    }

    for(int i = this->arraySize ,j =0; i<temp.arraySize;i++,j++){
        temp.ptr[i] = object.ptr[j];
    }

    return temp;


}

template<class T , class T2>
Queue<T,T2> Queue<T,T2>::operator--(){
    if(arraySize == 0) {
        std::cout << "Queue is empty!" << std::endl;
        return *this;
    }

    std:: cout<<"First element of queue ("<<ptr[0]<<") removed"<<std::endl;

    T *tempArray = new T [arraySize];

    for(int i = 0; i< arraySize; i++){
        tempArray[i] = ptr[i];
    }

    arraySize--;
    ptr = new T[arraySize];

    for(int i = 0; i< arraySize; i++){
        ptr[i] = tempArray[i+1];
    }

    delete []tempArray;

    return *this;

}



template<class T, class T2>
int Queue<T,T2>::getArraySize() {
    return arraySize;
}
template<class T, class T2>
void Queue<T,T2>:: print(){
    std:: cout<<"Queue: "<<std::endl;
    for(int i=0; i < arraySize; i++) {
        std::cout << " - "<< ptr[i] ;
    }
    std::cout<<std::endl;
}
template<class T, class T2>
int Queue<T,T2>::push(T value) {
    if(arraySize == maxArraySize){
        std:: cout << "Queue is full!"<<std::endl;
        return 0;
    }
    T *tempArray = new T [arraySize];
    for(int i = 0; i< arraySize; i++){
        tempArray[i] = ptr[i];
    }
    arraySize++;
    ptr = new T [arraySize];

    for(int i = 0; i< arraySize; i++){
        ptr[i] = tempArray[i];
    }

    ptr[arraySize-1] = value;

    delete []tempArray;
}

template<class T, class T2>
Queue<T,T2>::~Queue() {

    delete[]ptr;
}
template<class T, class T2>
int Queue<T,T2>::objectSize(T2 object){
    return  sizeof(object);
}





#endif //OOTP_LAB4_REALIZACIYAOFCLASSQUEUE_H
