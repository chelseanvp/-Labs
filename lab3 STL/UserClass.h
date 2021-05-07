#ifndef OOTP_LAB5_USERCLASS_H
#define OOTP_LAB5_USERCLASS_H
#include <string>
#include <list>

class UserClass{
private:
    int value;
    std::list<int> myList;
public:
    UserClass();
    UserClass(int value);
    void printList();
    void push_back(int value);
    void push_front(int value);
    void remove(int value);
    void remove(int value1,int value2);
    void merge(UserClass obj);




};


#endif //OOTP_LAB5_USERCLASS_H
