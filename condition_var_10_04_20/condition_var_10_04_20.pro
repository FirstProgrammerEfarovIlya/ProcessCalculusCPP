TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        difficulttask.cpp \
        easytask.cpp \
        main.cpp \
        main_work.cpp \
        mediumtask.cpp \
        task.cpp

HEADERS += \
    difficulttask.h \
    easytask.h \
    main_work.h \
    mediumtask.h \
    task.h

LIBS = -lpthread
