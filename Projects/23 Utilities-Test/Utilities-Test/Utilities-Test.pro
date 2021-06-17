TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/Utility/util.cpp \
        ../../!includes/Utility/utilrecord.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Stack/stack.h \
    ../../!includes/Utility/util.h \
    ../../!includes/Utility/utilrecord.h
