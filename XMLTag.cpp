#include "XMLTag.h"

XMLTag::XMLTag(const std::string &content, const std::string &name, const std::map<std::string, std::string> &attr,
               XMLTag *parent, const std::vector<XMLTag *> &children, int level) : content(content), name(name),
                                                                                   attributes(attr), parent(parent),
                                                                                   children(children), level(level) {};

XMLTag::XMLTag(int level) : level(level) {};

XMLTag::~XMLTag() {
    for (XMLTag *child: children) {
        delete child;
    }
}

const std::string &XMLTag::getName() const {
    return name;
}

const std::map<std::string, std::string> &XMLTag::getAttributes() const {
    return attributes;
}

int XMLTag::getLevel() const {
    return level;
}

const std::string &XMLTag::getContent() const {
    return content;
}

XMLTag* XMLTag::getParent() const {
    return parent;
}

//setter
void XMLTag::setContent(std::string content) {
    this->content = std::move(content);
}

void XMLTag::setName(std::string name) {
    this->name = std::move(name);
}

void XMLTag::setAttributes(std::map<std::string, std::string> attributes) {
    this->attributes = std::move(attributes);
}

// FIX: hier waren Pointer an der falschen Stelle
void XMLTag::setParent(XMLTag *parent) {
    this->parent = parent;
}

void XMLTag::setChildren(std::vector<XMLTag *> children) {
    this->children = std::move(children);
}

std::vector<XMLTag *> XMLTag::getChildren(){
    return children;
}

void XMLTag::setLevel(int level) {
    this->level = level;
}


void XMLTag::addChild(XMLTag *xmlTag) {
    children.push_back(xmlTag);
}

void XMLTag::addAttribute(std::string &attributeName, std::string &attributeValue) {
    attributes[attributeName] = attributeValue;
}

std::ostream &operator<<(std::ostream &os, const XMLTag &tag) {
    return os << tag.name << "-" << tag.content;
}
