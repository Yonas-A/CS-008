TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Doubly_Linked_List/doubly_linked_list.h \
    ../../!includes/Queue/queue.h \
    ../../!includes/Queue/queue_output.h \
    ../../!includes/Queue/queue_test.h \
    ../../!includes/Stack/stack.h \
    ../../!includes/Stack/stack_output.h \
    ../../!includes/Stack/stack_test.h \
    work_report_SnQ.h
