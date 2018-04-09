#ifndef TEST_DTDTAG_H
#define TEST_DTDTAG_H

#include <iostream>
#include <vector>
#include <ostream>
#include "XMLTag.h"


class DTDTag {
private:
    std::string name;
    std::vector<std::string> attributes;
    int level;   //level beim parsing erstellen, jedes mal eine stufe runter erhöhe level um 1,
    std::vector<DTDTag*> children;
    DTDTag *parent;
public:
    //TODO: validate tag information
    bool validate(const XMLTag &xmlTag) const;

    DTDTag(const std::string &name, const std::vector<std::string> &attr, int level,
           const std::vector<DTDTag *> &children, DTDTag *parent);

    // TODO: implement correct destructor
    ~DTDTag();

    // TODO: overloading output operator
    friend std::ostream &operator<<(std::ostream &os, const DTDTag &tag);


};


#endif //TEST_DTDTAG_H
