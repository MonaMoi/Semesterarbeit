//
// Created by shominees on 6.2.18.
//

#include <c++/iostream>
#include <c++/vector>
#include <ostream>
#include <map>

#ifndef TEST_XMLTAG_H
#define TEST_XMLTAG_H


class XMLTag {
private:
    std::string content="";
    std::string name;
    std::map<std::string,std::string> attributes={};  //Attribute als Map, damit man sie als zwei verschiedene typen abspeichern, Map speicher Keyvalues(Key + passender Value)
    XMLTag *parent;  //Tag kennt parent und alle seine Kinder
    std::vector<XMLTag*> children;
    int level;
public:
    XMLTag(const std::string &content, const std::string &name, const std::map<std::string,std::string> &attr, XMLTag *parent,
           const std::vector<XMLTag *> &children, int level);

    XMLTag(int level);

    void setcontent();
    void setname();
    void setattributes();
    void setparent();
    void setchildren();
    void setlevel();

    // TODO: implement correct destructor
    ~XMLTag();

    const std::string &getName() const;

    const std::map<std::string,std::string> &getAttr() const;

    const std::string &getcontent() const;

    int getLevel() const;

    // TODO: implement add child option
    void addChild(XMLTag *xmlTag);

    // TODO: implement add attribute option, MEthode um Werte/atrribute in die Map einzufügen
    void addAttribute(std::string &attributeName, std::string &attributeValue);

    // TODO: overload output operator
    friend std::ostream &operator<<(std::ostream &os, const XMLTag &tag);


};


#endif //TEST_XMLTAG_H
