TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/BST/bst.h \
    ../../!includes/BST/bst_test.h \
    ../../!includes/Binary_Search_Tree/binary_search_tree.h \
    Interface/bst_interface.h \
#    Interface/bst_output.h \
#    bst_work_report.h
