TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/FTokenizer/ftokenizer.cpp \
        ../../!includes/STokenizer/stokenizer.cpp \
        ../../!includes/STokenizer/stokenizer_table.cpp \
        ../../!includes/Token/token_strings.cpp \
        main.cpp

HEADERS += \
    ../../!includes/FTokenizer/ftokenizer.h \
    ../../!includes/STokenizer/stokenizer.h \
    ../../!includes/STokenizer/stokenizer_table.h \
    ../../!includes/Token/token_strings.h \
    FTokenizer_output.h \
#    FTokenizer_workReport.h
