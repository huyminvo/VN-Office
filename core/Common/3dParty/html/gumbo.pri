INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

core_linux:QMAKE_CFLAGS += -std=c99
core_windows:INCLUDEPATH += $$PWD/gumbo-parser/visualc/include
core_windows:INCLUDEPATH += $$PWD/gumbo-parser/src

HEADERS += $$files($$PWD/gumbo-parser/src/*.h, true) \
           $$PWD/htmltoxhtml.h

SOURCES += $$files($$PWD/gumbo-parser/src/*.c, true) \
           $$PWD/htmltoxhtml.cpp
