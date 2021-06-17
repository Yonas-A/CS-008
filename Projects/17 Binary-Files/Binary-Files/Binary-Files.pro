TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../!includes/Record/record.cpp \
    main.cpp \

HEADERS += \
    ../../!includes/Bin_File_functions/bin_file_functions.h \
    ../../!includes/Record/record.h \
    ../../!includes/Record/record_test.h
