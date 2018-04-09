#include "DTDTag.h"

DTDTag::DTDTag(const std::string &name, const std::vector<std::string> &attr, int level,
               const std::vector<DTDTag *> &children, DTDTag *parent) : name(name), attributes(attr), level(level),
                                                                        children(children), parent(parent) {};

DTDTag::~DTDTag() { //Zur Sicherheit alle Pointer löschen
    delete &name;
    delete &parent;
    for(DTDTag * child: children) {
        delete &child;
    }
    for(std::string attribute: attributes) {
            delete &attribute;
    }
}

std::ostream &operator<<(std::ostream &os, const DTDTag &tag) {
    return os << tag.name << "-" << tag.level;
}

/*    std::ostream os;   //deklariere output
    os << tag.name << "-" << tag.level <<; //resOs?...infos des einzelnen DTD Tags hinzugefügt
    for(DTDTag *  child : children) {  //Rekursiv für alle Kinder wiederholen
        os << child;
    }
    return resOs;
}
*/
