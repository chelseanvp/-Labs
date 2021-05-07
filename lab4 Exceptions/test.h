#ifndef OOTP_LAB6_TEST_H
#define OOTP_LAB6_TEST_H
#include <iostream>

class test{
public:
    test(){
        std::cout<<"Constructor"<<std::endl;
    }

    ~test(){
        std::cout<<"Destructor"<<std::endl;
    }
};

#endif //OOTP_LAB6_TEST_H
