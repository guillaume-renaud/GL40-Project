#ifndef INTERFACUI_H
#define INTERFACUI_H
//***************************************************************************
//
// Jean-Charles CREPUT, Abdelkhalek MANSOURI
//
//***************************************************************************

#include <QtCore/QVariant>
#include <QApplication>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>

#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

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


class Ui_MainWindow : public QWidget
{

    Q_OBJECT

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

    QMenu *menuFichier, *menuOutils, *menuFenetre, *menuLangue , *menuAide;
    QAction *actionQuitter, *actionOutilsTest, *actionFenetreTest, *actionLangueAnglais, *actionLangueFrancais, *actionAideTest;
    QMenuBar *menuBarre;

    QSignalMapper* signalMapper;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString("MainWindow"));

        MainWindow->resize(1000, 750);
        MainWindow->setAnimated(true);

        menuBarre = new QMenuBar();

        menuFichier = menuBarre->addMenu("");
        menuOutils = menuBarre->addMenu("");
        menuFenetre = menuBarre->addMenu("");
        menuLangue = menuBarre->addMenu("");
        menuAide = menuBarre->addMenu("");

        actionQuitter = new QAction("", this);
        actionQuitter->setShortcut(QKeySequence("ctrl+Q"));

        actionOutilsTest = new QAction("", this);
        actionFenetreTest = new QAction("", this);
        actionLangueAnglais = new QAction("", this);
        actionLangueFrancais = new QAction("", this);
        actionAideTest = new QAction("", this);

        menuFichier->addAction(actionQuitter);
        menuOutils->addAction(actionOutilsTest);
        menuFenetre->addAction(actionFenetreTest);
        menuLangue->addAction(actionLangueAnglais);
        menuLangue->addAction(actionLangueFrancais);
        menuAide->addAction(actionAideTest);

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

        this->paintingMesh->getCamera()->addObserver(this->paintingMesh);
        this->optionFrame->setCamera(this->paintingMesh->getCamera());
        paramFrame->addObserver(paintingMesh);

        frameRight = new QFrame(centralWidget);
        frameRight->setObjectName(QString("frame"));
        frameRight->setMaximumSize(QSize(140, 16777215));
        frameRight->setFrameShape(QFrame::StyledPanel);
        frameRight->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameRight, 0, 2, 1, 1);

        interactionFrame = new InteractionFrame(frameRight);
        interactionFrame->addObserver(paintingMesh);

        MainWindow->setCentralWidget(centralWidget);
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);

        signalMapper = new QSignalMapper (this);

        updateMenuLanguage("FR");
        updateLanguage("FR");

        connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

        connect(actionLangueAnglais, SIGNAL(triggered()), signalMapper, SLOT(map()));
        connect(actionLangueFrancais, SIGNAL(triggered()), signalMapper, SLOT(map()));

        signalMapper -> setMapping(actionLangueAnglais, "EN");
        signalMapper -> setMapping(actionLangueFrancais, "FR");

        connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(updateLanguage(QString))) ;
    }

    void updateMenuLanguage(QString language)
    {
        if(language == "FR")
        {
            menuFichier->setTitle("&Fichier");
            menuOutils->setTitle("&Outils");
            menuFenetre->setTitle("&Fenetre");
            menuLangue->setTitle("&Langue");
            menuAide->setTitle("&Aide");

            actionOutilsTest->setText("&TestOutils");
            actionFenetreTest->setText("&TestFenetre");
            actionAideTest->setText("&TestAide");
            actionQuitter->setText("&Arrêter le programme");
            actionLangueAnglais->setText("&Anglais");
            actionLangueFrancais->setText("&Français");
        }
        else if(language == "EN")
        {
            menuFichier->setTitle("&File");
            menuOutils->setTitle("&Tools");
            menuFenetre->setTitle("&Window");
            menuLangue->setTitle("&Language");
            menuAide->setTitle("&Help");

            actionOutilsTest->setText("&ToolsTest");
            actionFenetreTest->setText("&WindowTest");
            actionAideTest->setText("&HelpTest");
            actionQuitter->setText("&Quit");
            actionLangueAnglais->setText("&English");
            actionLangueFrancais->setText("&French");
        }
        else
            qDebug() << "Langue non reconnue !";
    }


    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "POPIP Viewer ", 0));
    }

private slots :
    void updateLanguage(QString language)
    {
        updateMenuLanguage(language);

        if(language == "FR")
        {
            paramFrame->translateTwoSidedGroupBox((char*)"2D-3D");
            paramFrame->translateView2DEnabledRadio((char*)"2D");
            paramFrame->translateView2DDisabledRadio((char*)"3D");
            paramFrame->translateColorsGroupBox((char*)"Couleurs");
            paramFrame->translateColorsEnabledRadio((char*)"Activé");
            paramFrame->translateColorsDisabledRadio((char*)"Désactivé");
            paramFrame->translateDisplayGroupBox((char*)"Affichage");
            paramFrame->translateDisplayMRadio((char*)"Maille");
            paramFrame->translateDisplayTRadio((char*)"Triangles");
            paramFrame->translateDisplayPRadio((char*)"Points");
            paramFrame->translateDisplayLRadio((char*)"Lignes");
            paramFrame->translateLabel((char*)"Affichage des\nparametres");

            optionFrame->translateOptionsGroupBox((char*) "Vues Prédéfinies");
            optionFrame->translateOptionView1((char*) "Vue 1");
            optionFrame->translateOptionView2((char*) "Vue 2");
            optionFrame->translateOptionView3((char*) "Vue 3");
            optionFrame->translateOptionView4((char*) "Vue 4");
            optionFrame->translateOptionView5((char*) "Vue 5");
            optionFrame->translateOptionView6((char*) "Vue 6");
            optionFrame->translateLabel((char*) "Options de visualisation");

            interactionFrame->translateLabel((char*) "Intéractions");
        }
        else if(language == "EN")
        {
            paramFrame->translateTwoSidedGroupBox((char*)"2D-3D");
            paramFrame->translateView2DEnabledRadio((char*)"2D");
            paramFrame->translateView2DDisabledRadio((char*)"3D");
            paramFrame->translateColorsGroupBox((char*)"Colors");
            paramFrame->translateColorsEnabledRadio((char*)"Enable");
            paramFrame->translateColorsDisabledRadio((char*)"Disable");
            paramFrame->translateDisplayGroupBox((char*)"Display");
            paramFrame->translateDisplayMRadio((char*)"Mesh");
            paramFrame->translateDisplayTRadio((char*)"Triangles");
            paramFrame->translateDisplayPRadio((char*)"Points");
            paramFrame->translateDisplayLRadio((char*)"Lines");
            paramFrame->translateLabel((char*)"Display\nparameters");

            optionFrame->translateOptionsGroupBox((char*) "Preset Views");
            optionFrame->translateOptionView1((char*) "View 1");
            optionFrame->translateOptionView2((char*) "View 2");
            optionFrame->translateOptionView3((char*) "View 3");
            optionFrame->translateOptionView4((char*) "View 4");
            optionFrame->translateOptionView5((char*) "View 5");
            optionFrame->translateOptionView6((char*) "View 6");
            optionFrame->translateLabel((char*) "Vizualisation options");

            interactionFrame->translateLabel((char*) "Interactions");
        }
        else
            qDebug() << "Langue " << language << " non reconnue !";
    }

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}

#endif // INTERFACUI_H
