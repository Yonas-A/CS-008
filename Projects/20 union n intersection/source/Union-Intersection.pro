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
    ../../!includes/Union_n_Intersection/intersection.h \
    ../../!includes/Union_n_Intersection/union.h \
    ../../!includes/Union_n_Intersection/union_intersection_helper.h

