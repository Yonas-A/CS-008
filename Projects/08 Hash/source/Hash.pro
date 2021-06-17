TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/Random/random.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Hash/chained_hash.h \
    ../../!includes/Hash/double_hash.h \
    ../../!includes/Hash/hash_interactive_test.h \
    ../../!includes/Hash/hash_random_test.h \
    ../../!includes/Hash/open_hash.h \
    ../../!includes/Random/random.h \
    ../../!includes/Hash/Record/record.h \
#    hash_work_report.h



