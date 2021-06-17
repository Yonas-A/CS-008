TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
#        ../../!includes/Random/random.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Array_Functions/array_functions.h \
    ../../!includes/Array_Functions/array_functions_test.h \
    ../../!includes/BPlus_Tree/bplus_tree.h \
    ../../!includes/BPlus_Tree/bplus_tree_test.h \
#    ../../!includes/Random/random.h \
#    random_test.h
