include(../common_top.pri)

TEMPLATE = app
CONFIG += meegotouch

DEPENDPATH += .
INCLUDEPATH += 	. \

include(../common_check.pri)

LIBS += -Wl,-rpath=$${MALIIT_PLUGINS_DIR} -lmeego-keyboard

HEADERS += ut_mimwordtracker.h \

SOURCES += ut_mimwordtracker.cpp \

