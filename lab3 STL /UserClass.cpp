#include "UserClass.h"
#include<list>
#include <iostream>

UserClass::UserClass() { }

UserClass::UserClass(int value) {
    push_back(value);
}

void UserClass::push_back(int value) {
    myList.push_back(value);
}

void UserClass::printList() {
    std::cout<<"Look up List:"<<std::endl;
    for (int & it : myList) {
        std::cout<< it << " ";
    }
    std::cout<<std::endl;
}

void UserClass::push_front(int value) {
    myList.push_front(value);
}

void UserClass::remove(int value) {
    myList.remove(value);
}

void UserClass::remove(int value1, int value2) {
    int N=0;
    std::list<int>::iterator it1,it2;
    for (int & it : myList) {
        if(it == value1){
            value1 = N;
            std::cout<<value1<<std::endl;
            break;
        }
        N++;
    }
    it1 = myList.begin();
    advance (it1,N+1);
    it2 = it1;
    if(*it2+value2 > *myList.end()){
        it2=myList.end();
    }else{
        advance (it2,value2);
    }

    myList.erase (it1,it2);


}

void UserClass::merge(UserClass obj) {
    myList.merge(obj.myList);
}
