#-------------------------------------------------
#
# Project created by QtCreator 2014-05-03T10:06:14
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simongame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    board.cpp \
    settings.cpp \
    run.cpp \
    settings_container.cpp \
    csv_writer.cpp \
    testrun.cpp

HEADERS  += mainwindow.h \
    board.h \
    run.h \
    settings_container.h \
    settings.h \
    Leap.h \
    LeapMath.h \
    csv_writer.h \
    testrun.h

FORMS    += mainwindow.ui \
    board.ui \
    settings.ui

OTHER_FILES +=

RESOURCES += \
    resources/icons.qrc \
    resources/sounds.qrc

macx: LIBS += -L$$PWD/lib -lLeap

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

#copies library libLeap.dylib from project folder into build folder for mac
#TODO: add similar command for other os's
macx {
    copydata.commands = cp $$PWD/lib/libLeap.dylib $$OUT_PWD/simongame.app/Contents/MacOS/
}
unix:!macx {
    copydata.commands = cp $$PWD/lib_linux/newlib/lib/x64/libLeap.so $$OUT_PWD/
}
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata



unix:!macx: LIBS += -L$$PWD/lib_linux/newlib/lib/x64/ -lLeap

INCLUDEPATH += $$PWD/lib_linux/newlib/lib/x64
DEPENDPATH += $$PWD/lib_linux/newlib/lib/x64
