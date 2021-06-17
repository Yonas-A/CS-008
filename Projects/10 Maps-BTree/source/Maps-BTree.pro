TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Map/B_Tree/map.h \
    ../../!includes/Map/B_Tree/map_test.h \
    ../../!includes/Map/B_Tree/multimap.h \
    ../../!includes/Map/B_Tree/multimap_test.h \
    ../../!includes/Pair/multipair.h \
    ../../!includes/Pair/pair.h

