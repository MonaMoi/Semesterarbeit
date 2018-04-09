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

    while (!input.eof()) {
        parser->parseXMLData(input);
       // parser->parseMetaData(input);
    }
    input.close();

    parser->debug_output();

    return EXIT_SUCCESS;
}
