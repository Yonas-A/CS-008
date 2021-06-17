TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/AVL/avl.h \
    ../../!includes/AVL/avl_test.h \ \
    ../../!includes/Binary_Search_Tree/binary_search_tree.h \
    ../../!includes/Binary_Search_Tree/union.h \
#    Interface/avl_output.h \
    Interface/avl_interface.h \
    work_report_avl.h

