#-------------------------------------------------
#
# Project created by QtCreator 2013-01-09T01:18:19
#
#-------------------------------------------------

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT           += core gui opengl widgets
TARGET        = ../bin/viewer
TEMPLATE      = app

CONFIG += static
CONFIG += console

SOURCES      += \
    src/main.cpp \
    src/camera.cpp

HEADERS      += \
    include/paramframe.h \
    include/paintingmesh.h \
    include/ctrlwidget.h \
    include/camera.h \
    include/interfaceUI.h \
    include/optionframe.h \
    include/interactionframe.h

FORMS        +=


OTHER_FILES  +=

######################################################
#
# For ubuntu, add environment variable into the project.
# Projects->Build Environment
# LD_LIBRARY_PATH = /usr/local/cuda/lib
#
######################################################



win32:{


  INCLUDEPATH  += D:/LIB/Qt/5.4/msvc2012_opengl/include D:/LIB/Qt/5.4/msvc2012_opengl/include\QtOpenGL
  INCLUDEPATH  += include ../../basic_components/components/include

}

unix:{

  ##############################################################################
  # Here to add the specific QT and BOOST paths according to your Linux system.
  # For H.W's system
  INCLUDEPATH  += ../include

  INCLUDEPATH  += /home/mansouri/Qt/5.4/gcc_64/include


  QMAKE_CXXFLAGS += -std=c++0x

  INCLUDEPATH  += ../../basic_components/components/include
  INCLUDEPATH  += include
}


