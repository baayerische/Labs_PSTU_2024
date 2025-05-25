QT += core gui widgets opengl openglwidgets

TARGET = BinaryTree
TEMPLATE = app

SOURCES += \
    main.cpp \
    point.cpp \
    openglwidget.cpp

HEADERS += \
    point.h \
    openglwidget.h

# Подключение библиотеки OpenGL для Windows
win32 {
    LIBS += -lopengl32 -lglu32
}
