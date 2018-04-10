#include <vector>
#include <fstream>
#include "DataObject.h"
#include "XMLTag.h"
#include "DTDTag.h"

#ifndef TEST_PARSER_H
#define TEST_PARSER_H


class Parser {
private:

    std::vector<DataObject*> dataObjects;
    XMLTag* xmlRoot = nullptr;
    DTDTag* dtdRoot = nullptr;

public:

    Parser() = default;

    ~Parser();

    static std::vector<std::string> split_by_delimiter(std::string &reference, char delimiter);

    void parseMetaData(std::ifstream &data);

    void parseXMLData(std::ifstream & data);

    // TODO: nur für Stufe 4
    void parseDTDData(std::ifstream & data);

    // TODO: den XML-Baum durchiterieren und an der richtigen Stelle (im Child Vector) ein neues Tag mit den neuen Metainfos einfügen (Parent setzen nicht vergessen!)
    void mergeData();

    // TODO: den XML-Baum durchiterieren alle Taginfos auslesen und wieder mit '<' und '>' in den output writer schreiben (<<operator overloaden?)
    void createNewXML(std::ostream &xml);

    // for debugging
    void debug_output();

    void printXMLTree(XMLTag*current);

    const std::string &getRoot() const;

};


#endif //TEST_PARSER_H
