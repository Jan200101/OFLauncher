QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR         = bin	# build/bin
OBJECTS_DIR     = obj	# build/obj
MOC_DIR         = moc	# build/moc

DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CXXFLAGS += \
               -Wall \
               -Wextra \
               -pedantic \
               -Winit-self \
               -Wcast-align \
               -Wuninitialized \
               -Wpointer-arith \
               -Wunreachable-code \

CONFIG += c++11

SOURCES += \
    $$PWD/src/main.cpp \
    $$PWD/src/oflauncher.cpp

HEADERS += \
    $$PWD/inc/oflauncher.hpp


INCLUDEPATH += \
	$$PWD/src \
	$$PWD/inc

//TRANSLATIONS += \
//    $$PWD/lang/OFLauncher_en_US.ts

RESOURCES      += \
               res/images.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
