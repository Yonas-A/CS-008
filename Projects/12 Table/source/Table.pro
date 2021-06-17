TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../!includes/RPN/rpn.cpp \
    ../../!includes/Record/record.cpp \
    ../../!includes/Shunting_Yard/shunting_yard.cpp \
    ../../!includes/Table/table.cpp \
    ../../!includes/Utility/util.cpp \
    ../../!includes/Utility/utilrecord.cpp \
    main.cpp

HEADERS += \
    ../../!includes/BPlus_Tree/bplus_tree.h \
    ../../!includes/Bin_File_functions/bin_file_functions.h \
    ../../!includes/Map/BPlus_Tree/multimap.h \
    ../../!includes/Pair/multipair.h \
    ../../!includes/RPN/rpn.h \
    ../../!includes/Shunting_Yard/shunting_yard.h \
    ../../!includes/Record/record.h \
    ../../!includes/Table/table.h \
    ../../!includes/Table/table_test.h \
    ../../!includes/Utility/util.h \
    ../../!includes/Utility/utilrecord.h


#DISTFILES += \
#    README.md
