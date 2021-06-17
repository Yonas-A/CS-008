TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Array_Functions/array_functions.h \
    ../../!includes/Array_Functions/array_functions_test.h \
    ../../!includes/B_Tree/b_tree_test.h \
    ../../!includes/B_Tree/b_tree.h


