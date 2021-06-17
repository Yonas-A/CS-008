TEMPLATE = app
CONFIG += console c++14
#QMAKE_CXXFLAGS += -std=c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/STokenizer/stokenizer.cpp \
        ../../!includes/STokenizer/stokenizer_table.cpp \
        ../../!includes/Token/token_strings.cpp \

HEADERS += \
    ../../!includes/STokenizer/stokenizer.h \
    ../../!includes/STokenizer/stokenizer_table.h \
    ../../!includes/Token/token_strings.h
