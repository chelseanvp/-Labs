#ifndef OOTP_LAB5_LIST_H
#define OOTP_LAB5_LIST_H
#include <iostream>
using namespace std;

class List {
private:
    int side_length;
public:
    explicit List(int side_length = 5);

    int get_side_length() const;

    bool operator>(const List &other) const;
    bool operator<(const List &other) const;
    bool operator==(const List &other) const;
    bool operator!=(const List &other) const;

    friend ostream &operator<<(ostream &out, const List &list) {
        out << list.side_length;
        return out;
    }

    friend istream& operator>>(istream &in, List &list) {
        in >> list.side_length;
        return in;
    }

    ~List() = default;
};
#endif //OOTP_LAB5_LIST_H
