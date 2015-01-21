#-------------------------------------------------
#
# Project created by QtCreator 2015-01-21T11:09:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayTracerDvp
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        gui/mainwindow.cpp \
    utils/vector3d.cpp \
    rendering/ray.cpp

HEADERS  += gui/mainwindow.hpp \
    utils/vector3d.hpp \
    utils/make_unique.hpp \
    utils/noncopiable.hpp \
    utils/noninstantiable.hpp \
    utils/pimpl.hpp \
    utils/deep_ptr.hpp \
    rendering/ray.hpp
