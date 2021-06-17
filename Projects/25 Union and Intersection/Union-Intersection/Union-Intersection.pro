TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Map/BPlus_Tree/map.h \
    ../../!includes/Map/BPlus_Tree/multimap.h \
    ../../!includes/Sort/heap_sort.h \
    ../../!includes/Union_n_Intesection/intersection_and_union.h
