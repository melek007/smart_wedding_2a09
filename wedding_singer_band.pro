QT       += core gui sql printsupport multimedia serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bandM.cpp \
    cameraman.cpp \
    clothes.cpp \
    compte.cpp \
    connexion_base.cpp \
    honeymoon.cpp \
    location_voiture.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    reservation.cpp \
    salle.cpp \
    singerM.cpp \
    statistiques.cpp \
    statsband.cpp \
    the_band.cpp \
    theme.cpp \
    traiteur.cpp \
    vip_wedding.cpp \
    voiture.cpp

HEADERS += \
    arduino.h \
    bandM.h \
    cameraman.h \
    clothes.h \
    compte.h \
    connexion_base.h \
    honeymoon.h \
    location_voiture.h \
    mainwindow.h \
    personnel.h \
    reservation.h \
    salle.h \
    singerM.h \
    statistiques.h \
    statsband.h \
    the_band.h \
    theme.h \
    traiteur.h \
    vip_wedding.h \
    voiture.h

FORMS += \
    mainwindow.ui \
    statistiques.ui \
    statsband.ui \
    the_band.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sounds.qrc