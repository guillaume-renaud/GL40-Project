#ifndef INTERFACUI_H
#define INTERFACUI_H
//***************************************************************************
//
// Jean-Charles CREPUT, Abdelkhalek MANSOURI
//
//***************************************************************************

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>

#include <QGridLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QTabWidget>
#include <QWidget>

#include "paintingmesh.h"
#include "paramframe.h"
#include <QMainWindow>
#include "optionframe.h"
#include "interactionframe.h"


class Ui_MainWindow
{

public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QFrame *frameBottom, *frameRight;
    QWidget *Mesh;
    QGridLayout *gridLayout_5;
    PaintingMesh *paintingMesh;
    ParamFrame *paramFrame;
    OptionFrame *optionFrame;
    InteractionFrame *interactionFrame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString("MainWindow"));

        MainWindow->resize(1000, 750);
        MainWindow->setAnimated(true);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString("centralWidget"));
        centralWidget->setEnabled(true);

        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString("gridLayout"));

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString("frame"));
        frame->setMaximumSize(QSize(140, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        paramFrame = new ParamFrame(frame);

        frameBottom = new QFrame(centralWidget);
        frameBottom->setObjectName(QString("frameBottom"));
        frameBottom->setMaximumSize(QSize(16777215, 101));
        frameBottom->setSizeIncrement(QSize(0, 0));
        frameBottom->setFrameShape(QFrame::StyledPanel);
        frameBottom->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameBottom, 1, 0, 1, 0);

        optionFrame = new OptionFrame(frameBottom);

        Mesh = new QWidget(centralWidget);
        Mesh->setObjectName(QString("Mesh"));
        Mesh->setEnabled(true);

        gridLayout_5 = new QGridLayout(Mesh);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString("gridLayout_5"));

        paintingMesh = new PaintingMesh(Mesh);
        paintingMesh->setObjectName(QString("paintingMesh"));

        gridLayout_5->addWidget(paintingMesh);

        gridLayout->addWidget(Mesh, 0, 1, 1, 1);

        frameRight = new QFrame(centralWidget);
        frameRight->setObjectName(QString("frame"));
        frameRight->setMaximumSize(QSize(140, 16777215));
        frameRight->setFrameShape(QFrame::StyledPanel);
        frameRight->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameRight, 0, 2, 1, 1);

        interactionFrame = new InteractionFrame(frameRight);

        MainWindow->setCentralWidget(centralWidget);
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }
    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "POPIP Viewer ", 0));
    }
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}

#endif // INTERFACUI_H
