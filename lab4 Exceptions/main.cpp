#include <iostream>
#include "test.h"

void task1(){
    try{
        test obj1;
        test obj2;

        throw -1;
    }catch(int a) {
        std::cerr << "We caught an int exception with value: " << a << '\n';
    }

}

void function() {
    throw -2;
}

void task2() {
    try {
        int i=3;
            if (i > 2) {
                if (i < 5) {
                    if (i == 3) {
                            function();
                    }
                }
            }
        }
    catch(int a) {
        std::cerr << "We caught an int exception with value: " << a << '\n';
    }
}

int main() {
    std::cout<<"===TASK1==="<<std::endl;
    task1();

    std::cout<<"===TASK2==="<<std::endl;
    task2();

}
