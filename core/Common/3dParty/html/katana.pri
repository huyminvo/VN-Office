core_windows:INCLUDEPATH += $$PWD/katana-parser/visualc/include
core_windows:INCLUDEPATH += $$PWD/katana-parser/src

HEADERS += $$files($$PWD/katana-parser/src/*.h, true)
SOURCES += $$files($$PWD/katana-parser/src/*.c, true)
