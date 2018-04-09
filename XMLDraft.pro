TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    DataObject.cpp \
    DTDTag.cpp \
    main.cpp \
    Parser.cpp \
    XMLTag.cpp

HEADERS += \
    DTDTag.h \
    Parser.h \
    XMLTag.h \
    DataObject.h

SUBDIRS += \
    XMLDraft.pro

DISTFILES += \
    ../build-XMLDraft-Desktop_Qt_5_9_3_MinGW_32bit-Debug/data.txt \
    ../build-XMLDraft-Desktop_Qt_5_9_3_MinGW_32bit-Debug/daten.xml
