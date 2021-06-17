TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Heap/heap.h \
    ../../!includes/Heap/heap_test.h \ \
    Interface/heap_interface.h
