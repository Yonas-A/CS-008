TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
CORE += QT

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Map/BPlus_Tree/map.h \
    ../../!includes/Map/BPlus_Tree/map_test.h \
    ../../!includes/Map/BPlus_Tree/multimap.h \
    ../../!includes/Map/BPlus_Tree/multimap_test.h
