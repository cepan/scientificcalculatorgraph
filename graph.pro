TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    operand.cpp \
    operator.cpp \
    token.cpp \
    animate.cpp


LIBS += -L"/Users/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/Users/local/include"
DEPENDPATH += "/Users/local/include"

HEADERS += \
    rpn.h \
    constant.h \
    function.h \
    list.h \
    node.h \
    operand.h \
    operator.h \
    queue.h \
    stack.h \
    token.h \
    variable.h \
    animate.h \
    coordinate.h
