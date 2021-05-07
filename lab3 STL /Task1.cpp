#include <iostream>
#include <map>
#include <string>
#include "TASK1.h"

void printMultiMap( std::multimap<std::string,int> myMultiMap,std::string mapNumber){
    std::cout<<"________________"<<std::endl;
    std::cout<<"Look up "<<mapNumber<<" MultiMap:"<<std::endl;
    for (const auto &i : myMultiMap)
    {
        std::cout << "Key: " << i.first << "  Value: " << i.second << std::endl;
    }
}

void Task1(){
    std::multimap<std::string,int> myMultiMap = {{"Petya", 777}, {"Dima", 228}, {"Kiril", 888}};
    myMultiMap.emplace("Kolya", 555);

    printMultiMap(myMultiMap,"first");
    std::string key;

    std::cout << "remove some element: "<<std::endl;
    std::cout<<"Enter Key: "<<std::endl;
    std::cin>>key;
    auto j = myMultiMap.find(key);
    if(j!=myMultiMap.end()){
        myMultiMap.erase(key);
        std::cout<<key<<" was deleted!"<<std::endl;
    }else{
        std::cout<<"Key not found!"<<std::endl;
    }

    std::cout << "multiset lookup using iterator:  "<<std::endl;
    auto iterator = myMultiMap.begin();
    while(iterator != myMultiMap.end()) {
        std::cout << "Key: " << iterator->first << "  Value: " << iterator->second << std::endl;
        ++iterator;
    }

    std::multimap<std::string,int> myMultiMap2 = {{"Nikita", 772}, {"Grisha", 222}, {"Vladimir", 882}};
    printMultiMap(myMultiMap2,"second");

    std::cout<<"Enter key:"<<std::endl;
    std::cin>>key;
    int n;
    std::cout<<"Enter n:"<<std::endl;
    std::cin>>n;

    j = myMultiMap.find(key);
    if(j!=myMultiMap.end()){
        auto start = myMultiMap.find(key);
        ++start;

        auto end = start;
        for(int i = 0; i < n; i++) {
            if(end != myMultiMap.end())
                ++end;
        }
        myMultiMap.erase(start, end);

        auto iterator = myMultiMap2.begin();
        while(iterator != myMultiMap2.end()) {
            myMultiMap.emplace(iterator->first,iterator->second);
            ++iterator;
        }

        printMultiMap(myMultiMap,"first");



    }else{
        std::cout<<"Key not found!"<<std::endl;
    }

}
