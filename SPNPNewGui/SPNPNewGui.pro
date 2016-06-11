#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T16:55:53
#
#-------------------------------------------------

QT      += core gui
CONFIG	+=c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPNPNewGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

unix{
    DEFINES += LINUX
    LIBS += -L$$OUT_PWD/../HighLighter/ -lHighlighter
    LIBS += -L$$OUT_PWD/../SaveLoadFile/ -lSaveLoadFile
    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
    LIBS += -L$$OUT_PWD/../spnpclasses/ -lSPNPClasses
    LIBS += -L$$OUT_PWD/../PetriWidget/ -lPetriWidget
}

win32{
    DEFINES += WINDOWS

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../HighLighter/release/ -lHighlighter
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../HighLighter/debug/ -lHighlighter

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SaveLoadFile/release/ -lSaveLoadFile
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SaveLoadFile/debug/ -lSaveLoadFile

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/release/ -lSPNPClasses
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/debug/ -lSPNPClasses

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/release/ -lPetriWidget
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/debug/ -lPetriWidget
}

INCLUDEPATH += $$PWD/../HighLighter
DEPENDPATH += $$PWD/../HighLighter

INCLUDEPATH += $$PWD/../SaveLoadFile
DEPENDPATH += $$PWD/../SaveLoadFile

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser

INCLUDEPATH += $$PWD/../spnpclasses
DEPENDPATH += $$PWD/../spnpclasses

INCLUDEPATH += $$PWD/../PetriWidget
DEPENDPATH += $$PWD/../PetriWidget
