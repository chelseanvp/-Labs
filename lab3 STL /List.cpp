#include "List.h"

List::List(int side_length) {
    this->side_length = side_length;
}


int List::get_side_length() const {
    return side_length;
}

bool List::operator<(const List &other) const {
    return this->side_length < other.side_length;
}

bool List::operator>(const List &other) const {
    return this->side_length > other.side_length;
}

bool List::operator==(const List &other) const {
    return this->side_length == other.side_length;
}

bool List::operator!=(const List &other) const {
    return this->side_length != other.side_length;
}

