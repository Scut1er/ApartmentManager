QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Apartment.cpp \
    ApartmentContainer.cpp \
    DatabaseManager.cpp \
    addapartmentdialog.cpp \
    ap_actions.cpp \
    db_actions.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Apartment.h \
    ApartmentContainer.h \
    DatabaseManager.h \
    addapartmentdialog.h \
    ap_actions.h \
    db_actions.h \
    mainwindow.h

FORMS += \
    addapartmentdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
