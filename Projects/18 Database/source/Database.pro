TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/Parser/parser.cpp \
        ../../!includes/RPN/rpn.cpp \
        ../../!includes/Record/record.cpp \
        ../../!includes/SQL/sql.cpp \
        ../../!includes/STokenizer/stokenizer.cpp \
        ../../!includes/STokenizer/stokenizer_table.cpp \
        ../../!includes/Shunting_Yard/Token/left_paren.cpp \
        ../../!includes/Shunting_Yard/Token/number.cpp \
        ../../!includes/Shunting_Yard/Token/operator.cpp \
        ../../!includes/Shunting_Yard/Token/right_paren.cpp \
        ../../!includes/Shunting_Yard/Token/token.cpp \
        ../../!includes/Shunting_Yard/shunting_yard.cpp \
        ../../!includes/State_Machine/command_line_table.cpp \
        ../../!includes/Table/table.cpp \
        ../../!includes/Token/token_strings.cpp \
        ../../!includes/Utility/util.cpp \
        ../../!includes/Utility/utilrecord.cpp \
        main.cpp

HEADERS += \
    ../../!includes/BPlus_Tree/bplus_tree.h \
    ../../!includes/Bin_File_functions/bin_file_functions.h \
    ../../!includes/Enums/enumerations.h \
    ../../!includes/Map/BPlus_Tree/multimap.h \
    ../../!includes/Pair/multipair.h \
    ../../!includes/Parser/parser.h \
    ../../!includes/Queue/queue.h \
    ../../!includes/RPN/rpn.h \
    ../../!includes/RPN/rpn_test.h \
    ../../!includes/Record/record.h \
    ../../!includes/SQL/sql.h \
    ../../!includes/STokenizer/stokenizer.h \
    ../../!includes/STokenizer/stokenizer_table.h \
    ../../!includes/Shunting_Yard/Token/left_paren.h \
    ../../!includes/Shunting_Yard/Token/number.h \
    ../../!includes/Shunting_Yard/Token/operator.h \
    ../../!includes/Shunting_Yard/Token/right_paren.h \
    ../../!includes/Shunting_Yard/Token/token.h \
    ../../!includes/Shunting_Yard/shunting_yard.h \
    ../../!includes/Sort/heap_sort.h \
    ../../!includes/Stack/stack.h \
    ../../!includes/State_Machine/command_line_table.h \
    ../../!includes/Table/table.h \
    ../../!includes/Table/table_test.h \
    ../../!includes/Token/token_strings.h \ \
    ../../!includes/Utility/util.h \
    ../../!includes/Utility/utilrecord.h
