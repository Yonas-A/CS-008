TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/RPN/rpn.cpp \
        ../../!includes/Record/record.cpp \
        ../../!includes/STokenizer/stokenizer.cpp \
        ../../!includes/STokenizer/stokenizer_table.cpp \
        ../../!includes/Shunting_Yard/Token/left_paren.cpp \
        ../../!includes/Shunting_Yard/Token/number.cpp \
        ../../!includes/Shunting_Yard/Token/operator.cpp \
        ../../!includes/Shunting_Yard/Token/right_paren.cpp \
        ../../!includes/Shunting_Yard/Token/token.cpp \
        ../../!includes/Shunting_Yard/shunting_yard.cpp \
        ../../!includes/Table/table.cpp \
        ../../!includes/Token/token_strings.cpp \
        ../../!includes/Utility/util.cpp \
        ../../!includes/Utility/utilrecord.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Queue/queue.h \
    ../../!includes/RPN/rpn.h \
    ../../!includes/RPN/rpn_test.h \
    ../../!includes/Record/record.h \
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
    ../../!includes/Table/table.h \
    ../../!includes/Token/token_strings.h \ \
    ../../!includes/Union_n_Intesection/union_n_intersection.h \
    ../../!includes/Utility/util.h \
    ../../!includes/Utility/utilrecord.h
