TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/Parser/parser.cpp \
        ../../!includes/Record/record.cpp \
        ../../!includes/SQL/sql.cpp \
        ../../!includes/STokenizer/stokenizer.cpp \
        ../../!includes/STokenizer/stokenizer_table.cpp \
        ../../!includes/State_Machine/command_line_table.cpp \
        ../../!includes/Table/table.cpp \
        ../../!includes/Token/token_strings.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Enums/enumerations.h \
    ../../!includes/Map/BPlus_Tree/map.h \
    ../../!includes/Map/BPlus_Tree/multimap.h \
    ../../!includes/Parser/parser.h \
    ../../!includes/Queue/queue.h \
    ../../!includes/Record/record.h \
    ../../!includes/SQL/sql.h \
    ../../!includes/STokenizer/stokenizer.h \
    ../../!includes/STokenizer/stokenizer_table.h \
    ../../!includes/State_Machine/command_line_table.h \
    ../../!includes/Table/table.h \
    ../../!includes/Token/token_strings.h \
    ../../!includes/Token_string/token.h

