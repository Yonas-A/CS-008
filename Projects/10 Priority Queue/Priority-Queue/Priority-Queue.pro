TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Heap/heap.h \
    ../../!includes/Priority_Queue/pqueue.h \
    ../../!includes/Priority_Queue/pqueue_test.h \
    Interface/pqueue_interface.h \
#    Interface/pqueue_output.h \
    pqueue_work_report.h
