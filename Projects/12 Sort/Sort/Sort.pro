TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/Random/random.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Sort/bubble_sort.h \
    ../../!includes/Sort/heap_sort.h \
    ../../!includes/Sort/insertion_sort.h \
    ../../!includes/Random/random.h \
    ../../!includes/Sort/merge_sort.h \
    ../../!includes/Sort/quick_sort.h \
    ../../!includes/Timer/timer.h \
    ../../!includes/Sort/sort_test.h \
    Sort_work_report.h \
    sort_output.h
