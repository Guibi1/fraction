QT += widgets

TEMPLATE = app
TARGET = fraction

HEADERS += \
    fraction.h \
    stylefraction.h \
    fenfraction.h

SOURCES += \
    fraction.cpp \
    main.cpp \
    stylefraction.cpp \
    fenfraction.cpp




win32:CONFIG(release): LIBS += -L$$PWD/../Guibi/release/ -lGuibi
else:win32:CONFIG(debug): LIBS += -L$$PWD/../Guibi/debug/ -lGuibi
else:unix: LIBS += -L$$PWD/../Guibi/ -lGuibi

INCLUDEPATH += $$PWD/../Guibi
DEPENDPATH += $$PWD/../Guibi
