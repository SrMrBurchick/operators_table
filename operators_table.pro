QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=                                                                  \
        inc

HEADERS +=                                                                      \
        inc/common.hpp                                                          \
        inc/country.hpp                                                         \
        inc/country_model.hpp                                                   \
        inc/country_reader.hpp                                                  \
        inc/database.hpp                                                        \
        inc/db_component.hpp                                                    \
        inc/errors.hpp                                                          \
        inc/operator.hpp                                                        \
        inc/operator_model.hpp                                                  \
        inc/operator_reader.hpp                                                 \
        inc/system.hpp                                                          \

SOURCES +=                                                                      \
        src/common.cpp                                                          \
        src/country.cpp                                                         \
        src/country_model.cpp                                                   \
        src/country_reader.cpp                                                  \
        src/database.cpp                                                        \
        src/db_component.cpp                                                    \
        src/main.cpp                                                            \
        src/operator.cpp                                                        \
        src/operator_model.cpp                                                  \
        src/operator_reader.cpp                                                 \
        src/system.cpp                                                          \

RESOURCES += qml.qrc

INCLUDEPATH += $$_PRO_FILE_PWD_/external/sqlite
DEPENDPATH += $$_PRO_FILE_PWD_/external/sqlite

LIBS += -L$$_PRO_FILE_PWD_/external/sqlite -lsqlite3

DEFINES += "PROJECT_PATH=\"$$_PRO_FILE_PWD_\""

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = qml
QML2_IMPORT_PATH = qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
