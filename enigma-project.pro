TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    transformer.cpp \
    rotor.cpp \
    reflector.cpp

HEADERS += \
    transformer.h \
    rotor.h \
    reflector.h
