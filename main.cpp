#include <iostream>
#include "Parser.h"

using namespace std;

int main() {

    auto *parser = new Parser();
    std::string filename;
    std::ifstream input;

    std::cout << "Enter filename: " << std::endl;
    std::cin >> filename;

    input.open(filename);



back:
    cout << "############FILM SAMMLUNG############" << endl;
    cout << "#####################################" << endl;
    cout << "(s)uche " << endl;
    cout << "(e)xportiere " << endl;
    cout << "(z)eige " << endl;
    cout << "(h)ilfe" << endl;
    cout << "(b)eenden" << endl;
    cout << "#####################################" << endl;
    char eingabe;

    cin >> eingabe;
    switch (eingabe){
    case 's':
        break;
    case 'e':
        break;
    case 'z':
        break;
    case 'h':
        break;
    case 'b':
        input.close();
        return 0;
        break;
    default:
        cout << "Falsche Eingabe, druecke h fuer Hilfe" << endl;
        break;
    }

    goto back;

    while (!input.eof()) {
        parser->parseMetaData(input);
    }
    input.close();

    parser->debug_output();

    input.open("daten.xml"); // TODO: get file data !!! richtige datei?

    while (!input.eof()){
        parser->parseXMLData(input);


    parser->printXMLTree(parser->getRoot()); //TODO: implement getRoot !!!!
}
    return EXIT_SUCCESS;
}
