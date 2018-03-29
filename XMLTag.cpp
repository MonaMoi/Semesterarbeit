//
// Created by shominees on 6.2.18.
//

#include "XMLTag.h"

const std::string &XMLTag::getName() const {
    return name;
}

const std::map<std::string, std::string> &XMLTag::getAttr() const {
    return attributes;
}

int XMLTag::getLevel() const {
    return level;
}

const std::string &XMLTag::getcontent() const {
    return content;
}
XMLTag::XMLTag(const std::string &content, const std::string &name, const std::map<std::string,std::string> &attr,
               XMLTag *parent, const std::vector<XMLTag *> &children, int level) : content(content), name(name),
                                                                                   attributes(attr), parent(parent),
                                                                                   children(children), level(level) {};

XMLTag::XMLTag(int level) : level(level) {};

//setter
void XMLTag::setcontent(std::string content){
    this->content = content;
}

void XMLTag::setname(std::string name){
    this->name = name;
}

void XMLTag::setattributes(std::map<std::string,std::string> attributes){
    this->attributes = attributes;
}

void XMLTag::setparent(XMLTag *parent){
    this->*parent = *parent;
}

void XMLTag::setchildren(std::vector<XMLTag *> children){
    this->children = children;
}

void XMLTag::setlevel(int level){
    this->level = level;
}


void XMLTag::addChild(XMLTag *xmlTag){
    children.push_back(xmlTag);
}

void XMLTag::addAttribute(std::string &attributeName, std::string &attributeValue){
    attributes[attributeName].push_back(attributeValue);
}

std::ostream &operator<<(std::ostream &os, const XMLTag &tag) {
    return os << tag.name << "-" << tag.content;
}

XMLTag::~XMLTag(){
    for(XMLTag * child: children) {
        delete child;
    }
}
