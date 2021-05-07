#ifndef OOTP_LAB5_LIST_H
#define OOTP_LAB5_LIST_H
#include <iostream>
using namespace std;

class List {
private:
    int length;
public:
    explicit List(int length = 5);

    int get_side_length() const;

    bool operator>(const List &other) const;
    bool operator<(const List &other) const;
    bool operator==(const List &other) const;
    bool operator!=(const List &other) const;

    friend ostream &operator<<(ostream &out, const List &list) {
        out << list.length;
        return out;
    }

    friend istream& operator>>(istream &in, List &list) {
        in >> list.length;
        return in;
    }

    ~List();
};
#endif //OOTP_LAB5_LIST_H
