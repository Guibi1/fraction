QT += widgets

TEMPLATE = app
TARGET = Fraction

HEADERS += \
    fraction.h \
    stylefraction.h \
    fenfraction.h \
    fractiongui.h

SOURCES += \
    fraction.cpp \
    main.cpp \
    stylefraction.cpp \
    fenfraction.cpp \
    fractiongui.cpp




win32:CONFIG(release, debug | release): LIBS += -L$$PWD/../Guibi/release/ -lGuibi
else:win32:CONFIG(debug, debug | release): LIBS += -L$$PWD/../Guibi/debug/ -lGuibi
else:unix: LIBS += -L$$PWD/../Guibi/ -lGuibi

INCLUDEPATH += $$PWD/../Guibi
DEPENDPATH += $$PWD/../Guibi

