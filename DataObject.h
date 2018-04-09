
#ifndef TEST_DATAOBJECT_H
#define TEST_DATAOBJECT_H

#include <iostream>
#include <ostream>

class DataObject {
private:
    int id;
    std::string placeholder;
    int number;

public:
    DataObject(int id, const std::string &placeholder, int number);

    ~DataObject() = default;

    int getId() const;

    const std::string &getPlaceholder() const;

    int getNumber() const;

    // TODO: overloading output operator
    friend std::ostream &operator<<(std::ostream &os, const DataObject &object);

};


#endif //TEST_DATAOBJECT_H
