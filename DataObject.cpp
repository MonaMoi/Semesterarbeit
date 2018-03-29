
#include "DataObject.h"

DataObject::DataObject(int id, const std::string &placeholder, int number) : id(id),
                                                                             placeholder(placeholder),
                                                                             number(number) {}

int DataObject::getId() const {
    return id;
}

const std::string &DataObject::getPlaceholder() const {
    return placeholder;
}

int DataObject::getNumber() const {
    return number;
}

std::ostream &operator<<(std::ostream &os, const DataObject &object) {
    return os << object.id << "-" << object.number;
}
