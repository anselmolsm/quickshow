TEMPLATE = app
DESTDIR = ../../bin/

QT += declarative

SOURCES += main.cpp \
    qsviewerwindow.cpp

HEADERS += \
    qsviewerwindow.h

FORMS += \
    qsviewerwindow.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    viewer.qml
