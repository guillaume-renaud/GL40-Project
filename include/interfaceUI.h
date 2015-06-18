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
#include <QMessageBox>

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
    QAction *actionQuitter, *actionFigerEcran, *actionPleinEcran, *actionLangueAnglais, *actionLangueFrancais, *actionAPropos;
    QMenuBar *menuBarre;
    QMessageBox *aideMsgBox;

    QSignalMapper *signalMapper;
    QMainWindow* mainWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString("MainWindow"));

        MainWindow->resize(1000, 750);
        MainWindow->setAnimated(true);

        menuBarre = new QMenuBar(MainWindow);

        menuFichier = menuBarre->addMenu("");
        menuOutils = menuBarre->addMenu("");
        menuFenetre = menuBarre->addMenu("");
        menuLangue = menuBarre->addMenu("");
        menuAide = menuBarre->addMenu("");

        actionQuitter = new QAction("", this);
        actionQuitter->setShortcut(QKeySequence("ctrl+Q"));

        actionPleinEcran = new QAction("", this);
        actionPleinEcran->setShortcut(QKeySequence("ctrl+shift+F"));

        actionFigerEcran = new QAction("", this);

        actionLangueAnglais = new QAction("", this);
        actionLangueAnglais->setShortcut(QKeySequence("ctrl+shift+1"));

        actionLangueFrancais = new QAction("", this);
        actionLangueFrancais->setShortcut(QKeySequence("ctrl+shift+2"));

        actionAPropos = new QAction("", this);

        menuFichier->addAction(actionQuitter);
        menuOutils->addAction(actionFigerEcran);
        menuFenetre->addAction(actionPleinEcran);
        menuLangue->addAction(actionLangueAnglais);
        menuLangue->addAction(actionLangueFrancais);
        menuAide->addAction(actionAPropos);

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

        gridLayout->addWidget(frame, 1, 0, 1, 1);

        paramFrame = new ParamFrame(frame);

        frameBottom = new QFrame(centralWidget);
        frameBottom->setObjectName(QString("frameBottom"));
        frameBottom->setMaximumSize(QSize(16777215, 101));
        frameBottom->setSizeIncrement(QSize(0, 0));
        frameBottom->setFrameShape(QFrame::StyledPanel);
        frameBottom->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameBottom, 2, 0, 1, 0);

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

        gridLayout->addWidget(Mesh, 1, 1, 1, 1);

        this->paintingMesh->getCamera()->addObserver(this->paintingMesh);
        this->optionFrame->setCamera(this->paintingMesh->getCamera());
        paramFrame->addObserver(paintingMesh);

        frameRight = new QFrame(centralWidget);
        frameRight->setObjectName(QString("frame"));
        frameRight->setMaximumSize(QSize(140, 16777215));
        frameRight->setFrameShape(QFrame::StyledPanel);
        frameRight->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameRight, 1, 2, 1, 1);

        interactionFrame = new InteractionFrame(frameRight);
        interactionFrame->addObserver(paintingMesh);
        interactionFrame->setCamera(this->paintingMesh->getCamera());
        optionFrame->setInteractionFrame(this->interactionFrame);

        MainWindow->setCentralWidget(centralWidget);
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
        mainWindow = MainWindow;

        signalMapper = new QSignalMapper (this);

        updateMenuLanguage("FR");
        updateLanguage("FR");

        connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
        connect(actionAPropos, SIGNAL(triggered()), this, SLOT(aideSlot()));
        connect(actionFigerEcran, SIGNAL(triggered()), this, SLOT(figerVueSlot()));
        connect(actionPleinEcran, SIGNAL(triggered()), this, SLOT(pleinEcranSlot()));

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

            actionFigerEcran->setText("&Figer Vue");
            actionPleinEcran->setText("&Plein Ecran");
            actionAPropos->setText("&A propos...");
            actionQuitter->setText("&Arrêt");
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

            actionFigerEcran->setText("&Freeze View");
            actionPleinEcran->setText("&Full Screen");
            actionAPropos->setText("&About...");
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
            optionFrame->translateOptionView1((char*) "Vue 1", (char*) "Vue de face");
            optionFrame->translateOptionView2((char*) "Vue 2", (char*) "Vue du cote droit");
            optionFrame->translateOptionView3((char*) "Vue 3", (char*) "Vue du dessus");
            optionFrame->translateOptionView4((char*) "Vue 4", (char*) "Vue de derriere");
            optionFrame->translateOptionView5((char*) "Vue 5", (char*) "Vue du cote gauche");
            optionFrame->translateOptionView6((char*) "Vue 6", (char*) "Vue du dessous");
            optionFrame->translateResetView((char*) "Réinitialiser Vue", (char*) "Vue de départ");
            optionFrame->translateLabel((char*) "Options de\nvisualisation");

            interactionFrame->translateLabel((char*) "Intéractions");
            interactionFrame->translateStartTimer((char*) "Début traveling");
            interactionFrame->translateStopTimer((char*) "Arrêt traveling");
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
            optionFrame->translateOptionView1((char*) "View 1", (char*) "Face view");
            optionFrame->translateOptionView2((char*) "View 2", (char*) "Right view");
            optionFrame->translateOptionView3((char*) "View 3", (char*) "Top view");
            optionFrame->translateOptionView4((char*) "View 4", (char*) "Reverse view");
            optionFrame->translateOptionView5((char*) "View 5", (char*) "Left view");
            optionFrame->translateOptionView6((char*) "View 6", (char*) "Bottom view");
            optionFrame->translateResetView((char*) "Reset View", (char*) "Starting view");
            optionFrame->translateLabel((char*) "Vizualisation\noptions");

            interactionFrame->translateLabel((char*) "Interactions");
            interactionFrame->translateStartTimer((char*) "Start traveling");
            interactionFrame->translateStopTimer((char*) "Stop traveling");
        }
        else
            qDebug() << "Langue " << language << " non reconnue !";
    }

    void aideSlot()
    {
        aideMsgBox = new QMessageBox();
        aideMsgBox->setText("L'aide sera disponible très prochainement. Merci de votre patience !");
        aideMsgBox->setVisible(true);
    }

    void pleinEcranSlot()
    {
        mainWindow->setWindowState(mainWindow->windowState() ^ Qt::WindowFullScreen);
    }

    void figerVueSlot()
    {

    }

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}

#endif // INTERFACUI_H
