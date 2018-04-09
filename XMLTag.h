#include <iostream>
#include <vector>
#include <ostream>
#include <map>

#ifndef TEST_XMLTAG_H
#define TEST_XMLTAG_H


class XMLTag {
private:
    std::string content = "";
    std::string name;
    //Attribute als Map, damit man den Attributnamen (key) und dessen Wert (value) in einer Datenstruktur speichern kann
    std::map<std::string, std::string> attributes = {};
    //Tag kennt parent und alle seine Kinder
    XMLTag *parent;
    std::vector<XMLTag *> children;
    int level;

public:
    XMLTag(const std::string &content, const std::string &name, const std::map<std::string, std::string> &attr,
           XMLTag *parent, const std::vector<XMLTag *> &children, int level);

    explicit XMLTag(int level);

    ~XMLTag();

    // FIX: Die Setter waren nicht korrekt implementiert, deshalb wurden die vom Parser nicht gefunden
    void setContent(std::string content);

    void setName(std::string name);

    void setAttributes(std::map<std::string, std::string> attributes);

    void setParent(XMLTag *parent);

    void setChildren(std::vector<XMLTag *> children);

    void setLevel(int level);

    const std::string &getName() const;

    const std::map<std::string, std::string> &getAttributes() const;

    const std::string &getContent() const;

    XMLTag* getParent() const;

    int getLevel() const;

    void addChild(XMLTag *xmlTag);

    void addAttribute(std::string &attributeName, std::string &attributeValue);

    friend std::ostream &operator<<(std::ostream &os, const XMLTag &tag);
};

#endif //TEST_XMLTAG_H
