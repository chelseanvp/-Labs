#include "List.h"

List::List(int length) {
    this->length = length;
}


int List::get_side_length() const {
    return length;
}

bool List::operator<(const List &other) const {
    return this->length < other.length;
}

bool List::operator>(const List &other) const {
    return this->length > other.length;
}

bool List::operator==(const List &other) const {
    return this->length == other.length;
}

bool List::operator!=(const List &other) const {
    return this->length != other.length;
}

List::~List() {

}

