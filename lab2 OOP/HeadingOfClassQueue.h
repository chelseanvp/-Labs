// Created by Nikolay on 10.04.2021.
#pragma once
#ifndef OOTP_LAB4_HEADINGOFCLASSQUEUE_H
#define OOTP_LAB4_HEADINGOFCLASSQUEUE_H

template<class T , class T2 >
class Queue{
protected:
    T *ptr;
    int maxArraySize = 5;
    int arraySize{};

public:
    Queue();
    ~Queue();
    Queue(const Queue &other);
    void operator =(const Queue &other);
    Queue operator +(Queue object);
    Queue operator --();
    int getArraySize();
    void print();
    int push(T value);
    int pop();
    int objectSize(T2 object);



};

#endif //OOTP_LAB4_HEADINGOFCLASSQUEUE_H
