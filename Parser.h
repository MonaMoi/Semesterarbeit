#include <c++/vector>
#include <c++/fstream>
#include "DataObject.h"
#include "XMLTag.h"
#include "DTDTag.h"

#ifndef TEST_PARSER_H
#define TEST_PARSER_H


class Parser {
private:

    std::vector<DataObject*> dataObjects;
    XMLTag* xmlRoot;
    DTDTag* dtdRoot;

public:

    static std::vector<std::string> split_by_delimiter(std::string &reference, char delimiter); //Methode kann augerufen weerden ohne instanz aufzurufen (static)

    void parseMetaData(std::ifstream &data);

    // TODO: try to find a possible solution
    void parseDTDData(std::ifstream & data);

    void parseXMLData(std::ifstream & data);

    void createNewXML(std::ostream &xml); //einzelnde tag attribute durchiterriert und mit output writer definieren, wie overload nur klammern dazusetzen und children korrekt reinschreiben, dsnn mit overload in eine datei schreiben

    void default_output();

    Parser() = default;

    ~Parser();;

};


#endif //TEST_PARSER_H
