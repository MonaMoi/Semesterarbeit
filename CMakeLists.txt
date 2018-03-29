cmake_minimum_required(VERSION 3.8)
project(XMLParser_Draft_uncompleted)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp dataObjects/DataObject.cpp dataObjects/DataObject.h Parser.cpp Parser.h dataObjects/XMLTag.cpp dataObjects/XMLTag.h dataObjects/DTDTag.cpp dataObjects/DTDTag.h)
add_executable(XMLParser_Draft_uncompleted ${SOURCE_FILES})