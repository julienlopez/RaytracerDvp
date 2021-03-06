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
    rendering/ray.cpp \
    rendering/primitives/iprimitive.cpp \
    rendering/primitives/sphere.cpp \
    rendering/scene.cpp \
    rendering/raytracer.cpp \
    image.cpp \
    gui/screen.cpp

HEADERS  += gui/mainwindow.hpp \
    utils/vector3d.hpp \
    utils/make_unique.hpp \
    utils/noncopiable.hpp \
    utils/noninstantiable.hpp \
    utils/pimpl.hpp \
    utils/deep_ptr.hpp \
    rendering/ray.hpp \
    rendering/primitives/iprimitive.hpp \
    rendering/primitives/sphere.hpp \
    rendering/scene.hpp \
    rendering/raytracer.hpp \
    image.hpp \
    gui/screen.hpp
