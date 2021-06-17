TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/Shunting_Yard/Token/left_paren.cpp \
        ../../!includes/Shunting_Yard/Token/number.cpp \
        ../../!includes/Shunting_Yard/Token/operator.cpp \
        ../../!includes/Shunting_Yard/Token/right_paren.cpp \
        ../../!includes/Shunting_Yard/Token/token.cpp \
        ../../!includes/Shunting_Yard/shunting_yard.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Shunting_Yard/Token/left_paren.h \
    ../../!includes/Shunting_Yard/Token/number.h \
    ../../!includes/Shunting_Yard/Token/operator.h \
    ../../!includes/Shunting_Yard/Token/right_paren.h \
    ../../!includes/Shunting_Yard/Token/token.h \
#    ../../!includes/Shunting_Yard/Tokenizer/constants.h \
    ../../!includes/Shunting_Yard/shunting_yard.h
