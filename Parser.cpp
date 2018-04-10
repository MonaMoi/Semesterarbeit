
#include <iostream>
#include <sstream>
#include "Parser.h"
#include "XMLTag.h"

/**
 * This method reads text files.
 *
 * @param data from read text file
 */
void Parser::parseMetaData(std::ifstream &data) {

    for (std::string line; getline(data, line);) {
        std::vector<std::string> tokens = Parser::split_by_delimiter(line, ' ');
        if (!tokens.empty()) {
            int id = std::stoi(tokens[0]);
            std::string placeholder = tokens[1];
            int number = std::stoi(tokens[2]);
            auto dataObject = new DataObject(id, placeholder, number);
            this->dataObjects.push_back(dataObject);
        }
    }

}

// FIX: Klammern haben gefehlt, deshalb wurde der halb Code nicht erkannt
void Parser::parseXMLData(std::ifstream &data) {
    char nextChar;
    int level = 0;
    std::string buffer;
    XMLTag *parent = nullptr;
    auto *current = new XMLTag(level);  //Iterator
    XMLTag *child = nullptr;

    enum parserState {
        isStartTag, isEndTag, isAttribute, none
    };

    parserState state = none;

    // TODO: child Tag Logik in den Parser implementieren
    while (data.eof()) {
        data.get(nextChar);

        switch (nextChar) {
            case '<': {
                data.get(nextChar);
                if (nextChar == '/') {
                    state = isEndTag;
                    current->setContent(buffer);
                    buffer = "";
                } else {
                    data.putback(nextChar);
                    state = isStartTag;
                    parent = current; // current wird parent vom nächsten Tag
                    current = new XMLTag(level); // nächstes Tag
                    current->setParent(parent); // setze dem neuem Tag sein parent (altes Tag)
                    if (current->getContent().empty()){ //wenn content leer ist, ist der nächste Tag 1 Level tiefer
                        level++;
                        parent->addChild(current);
                }

                break;
            }
            case '>': {
                if (state == isStartTag) {
                    current->setName(buffer); //setzen den Namen
                    buffer = ""; //Puffer leeren
                }
                if (state == isAttribute) {
                    std::vector<std::string> token = Parser::split_by_delimiter(buffer, '=');
                    std::string key = token[0]; // simple Umbenennung der Übersicht halber
                    unsigned int max = token[1].size() - 2; // unsigned int => int der keine negative Werte haben kann
                    std::string value = token[1].substr(1, max); //Anfühtungszeichen wegschneiden
                    current->addAttribute(key, value); // Attribute map mit Wert gefüllt
                }
                if (state == isEndTag) {
                    current = current->getParent();
                    state = none;
                }
                break;
            }
            case ' ': {
                if (state == isStartTag) {
                    current->setName(buffer); //setzen den Namen
                    buffer = ""; // Puffer leeren
                    state = isAttribute;
                }
                break;
            }
            case '\n':
                break;
            default:
                buffer += nextChar;
                break;
        }
    }
}


void Parser::debug_output() {
    for (DataObject *dataObject : dataObjects) {
        std::cout << dataObject << std::endl;
    }
}
std::vector<std::string> Parser::split_by_delimiter(std::string &reference, char delimiter) {
    std::vector<std::string> tokenList;
    std::string token;

    std::stringstream ss(reference);
    while (getline(ss, token, delimiter)) {
        tokenList.push_back(token);
    }
    return tokenList;
}

Parser::~Parser() {
    for (DataObject *dataObject : dataObjects) {
        delete dataObject;
    }
    delete xmlRoot;
    delete dtdRoot;
}




///*
//#include <iostream>
//#include <sstream>
//#include "Parser.h"
//#include "XMLTag.h"

///**
// * This method reads text files.
// *
// * @param data from read text file
// */


//}
//*/
//void parseDTDData(std::ifstream &data){
//    char zeichen, letztes;
//    std::string puffer;


//    struct element {
//        int zahl;
//        char name[100];
//        char tags[10][100];
//        char valid[10][100];
//    };

//    struct element *jetzt;

//    enum zustandDTD{istStartTag, istEndTag, direktive, element, abhaengig, noise};

//    enum zustandDTD zustand = noise;
//    jetzt = new struct element;//existiert noch nicht
//    jetzt->zahl = 0;

//    //DTD iterieren
//    for(data.get(zeichen);!data.eof();data.get(zeichen)) {
//        switch(zeichen){
//        case '<':
//            zustand=direktive;
//            zaehler=0;
//            break;
//        case '>':
//            if(zustand!=noise){
//                if(letztes!=' '){
//                    puffer[zaehler]='\0';
//                    strcpy(jetzt->tags[jetzt->zahl],puffer);
//                    strcpy(jetzt->valid[jetzt->zahl],puffer);
//                    jetzt->zahl++;
//                }
//            }
//            zustand=noise;
//            break;

//        case ' ':
//            if(letztes==' '){
//                continue;
//            }
//            puffer[zaehler]= '\0';
//            zaehler=0;
//            switch (zustand) {
//            case direktive:
//                if(strcmp(puffer, "!ELEMENT")){

//                    std::cout << "Fehler!" <<std::endl;
//                    zustand=noise;
//                }else{
//                    zustand=element;
//                }
//            break;
//            case element:
//                strcpy(jetzt->name,puffer);
//                strcpy(jetzt->valid[jetzt->zahl],puffer);
//                zustand=abhaengig;
//                break;
//            case abhaengig:
//                strcpy(jetzt->tags[jetzt->zahl],puffer);
//                strcpy(jetzt->valid[jetzt->zahl],puffer);
//                jetzt->zahl++;

//                break;
//            }
//            break;

//        default:
//            if(zustand!=noise){
//                puffer[zaehler] = zeichen;
//            }
//            zaehler++;
//            break;
//}
//}
//}
// //TO DO: Parser logik für Siblings!!, Parent bleibt immer das gleiche (parent=current bleibt weg)
//void parseXMLData(std::ifstream &data) {
//    //Attlist.h und Token.h hinzufügen??
//  char zeichen;
//  int level = 0;
//  std::string puffer;
//  XMLTag *parent = NULL;
//  XMLTag *current = new XMLTag(level);  //Iterator
//  XMLTag *child = NULL;

//  enum zustand {istStartTag, istEndTag, zwischenTags, inNamen, erwarteAttribut};

//  zustand zustand;

//  while (data.eof()) {
//    data.get(zeichen);

//    switch(zeichen) {
//    case '<':{
//       data.get(zeichen);
//       if(zeichen=='/') {
//          zustand = istEndTag;
//          current->setcontent(puffer);
//          puffer="";
//       }
//       else {
//           data.putback(zeichen);
//           if (current!=NULL &&current->getcontent()==""){level++;} //current nicht 0, kein content, also einen tiefer, wenn current nicht 0 und content kein content hat( content sind weitere tag), dann gehen wir ein level hoch
//              zustand=istStartTag; //setzen
//              parent=current; //wird parent des nächsten ??
//              current=new XMLTag(level); //neues objekt
//              current->setparent(parent);
//          }

//       break;
//    }
//    case '>':{
//       if(zustand==istStartTag) {
//          current->setname(puffer); //setzen den namen
//          puffer =""; //Puffer leeren
//       }
//       if(zustand==erwarteAttribut){
//           std::vector<std::string> token = Parser::split_by_delimiter(puffer, '=');
//           std::string key = token[0]; //umbenennung von token in key
//           int max = token[1].size()-2;
//           std::string value= token[1].substr(1, max); //Anfühtungszeichen wegschneiden, oder length-1
//           current->addAttribute(key, value);//map element hinzugefügt was aus keyvalue besteht,
//       }
//       break;
//  }
//       //wenn map nicht klappt, ein einfaches OBjekt mit Attribut machen
//    case ' ':
//        if(zustand==istStartTag){
//            current->setname(puffer); //setzen den namen
//            puffer =""; //Puffer leeren
//            zustand=erwarteAttribut;
//        }
//        break;

//    case '\n':
//       break;

//    default:
//       puffer+=zeichen;
//       break;
//     }
//   }
//}


//void Parser::default_output() {
//    for(DataObject* dataObject : dataObjects) {
//        std::cout << dataObject << std::endl;
//    }
//}

//std::vector<std::string> Parser::split_by_delimiter(std::string &reference, char delimiter) {
//    std::vector<std::string> tokenList;
//    std::string token;

//    std::stringstream ss(reference);
//    while (getline(ss, token, delimiter)) {
//        tokenList.push_back(token);
//    }
//    return tokenList;
//}

//Parser::~Parser() {
//    for(DataObject * dataObject : dataObjects) {
//        delete dataObject;
//    }
//    delete xmlRoot;
//    delete dtdRoot;
//}
