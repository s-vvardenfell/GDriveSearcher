QT += quick

CONFIG += console c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        beast_handler.cpp \
        curl_handler.cpp \
        gdrive_handler.cpp \
        main.cpp \
        utility.cpp

RESOURCES += qml.qrc

INCLUDEPATH += \
        usr/include/x86_64-linux-gnu/curl \
        usr/include/curl \
        usr/local/include \
        usr/local/include/gq/
        /usr/include
        /usr/include/boost
#        #works if Document.h and others is in usr/local/include or
#        #need to point gq/Document.h

LIBS+= \
       -lcurl \
       -lgumbo \
       -lgq \
       -lpthread \
#        -lboost_system \
#        -lboost_thread \
#        -openssl \
       -lrt \
       -lssl \
       -lcrypto \

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    beast_handler.hpp \
    curl_handler.hpp \
    exception.hpp \
    gdrive_handler.hpp \
    utility.hpp
