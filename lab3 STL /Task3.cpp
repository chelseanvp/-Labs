#include <iostream>
#include <set>
#include <list>
#include <vector>
#include "List.h"
#include "TASK3.h"

using namespace std;

bool side_length_is_even(List list) {
    return (list.get_side_length() % 2) == 0;
}

void Task3() {
    List obj1;
    List obj3(5);
    List obj6(16);
    List obj7(12);
    List obj8(19);

    auto multiset1_comparator = [](List a, List b) {return a > b; };

    multiset<List, decltype(multiset1_comparator)> multiset1(multiset1_comparator);
    multiset1.insert(obj1);
    multiset1.insert(obj6);
    multiset1.insert(obj3);
    multiset1.insert(obj8);
    multiset1.insert(obj7);

    cout << "multiset1 look up: ";
    for(auto &item : multiset1)
        cout << item << " ";

    auto multiset_iterator = find_if(multiset1.begin(), multiset1.end(), side_length_is_even);
    cout << endl << "list with even side length: " << *multiset_iterator;

    list<List> list1;

    for(auto &item : multiset1)
        if(side_length_is_even(item))
            list1.push_back(item);

    cout << endl << "queue lookup: ";
    while(!list1.empty()) {
        cout << list1.front() << " ";
        list1.pop_front();
    }


    auto multiset2_comparator = [](List a, List b) { return a < b; };
    multiset<List, decltype(multiset2_comparator)> multiset2(multiset2_comparator);
    cout << endl << "sorting containers" << endl << "container1(multiset): ";
    for(auto &item : multiset1)
        multiset2.insert(item);

    for(auto &item : multiset2)
        cout << item << " ";

    vector<List> vector;
    while(!list1.empty()) {
        vector.push_back(list1.front());
        list1.pop_front();
    }

    sort(vector.begin(), vector.end());
    for(auto &item : vector)
        list1.push_back(item);

    cout << endl << "Container2: ";
    while(!list1.empty()) {
        cout << list1.front() << " ";
        list1.pop_front();
    }

    for(auto &item : multiset2)
        if(side_length_is_even(item))
            list1.push_back(item);

    multiset<List, decltype(multiset2_comparator)> multiset3(multiset2_comparator);
    for(auto &item : multiset2)
        multiset3.insert(item);

    while(!list1.empty()) {
        multiset3.insert(list1.front());
        list1.pop_front();
    }

    cout << endl << "Container3: ";
    for(auto &item : multiset3)
        cout << item << " ";

    int amount_elements = count_if(multiset3.begin(), multiset3.end(), side_length_is_even);
    cout << endl << "amount to condition elements: " << amount_elements << endl;

    amount_elements != 0 ? cout << "yes" <<endl : cout << "no"<<endl;

}