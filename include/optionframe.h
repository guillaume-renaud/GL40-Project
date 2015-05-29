#ifndef OPTIONFRAME_H
#define OPTIONFRAME_H

#include <QMainWindow>
#include <QtGui>

#include <QWidget>

#include "paintingmesh.h"
#include <QGroupBox>
#include <QHeaderView>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QPushButton;
QT_END_NAMESPACE

class OptionFrame : public QWidget
{
    Q_OBJECT

private:

    QLabel *label;
    PaintingMesh *pme;
    QHBoxLayout *mainHorizontalLayout;
    QGroupBox *optionsGroupBox;
    QGridLayout *gridLayout;
    QPushButton *optionView1, *optionView2, *optionView3, *optionView4, *optionView5, *optionView6;
    CCamera* camera;

public:
    explicit OptionFrame(QFrame *parent = 0)
    {
        mainHorizontalLayout = new QHBoxLayout(parent);
        mainHorizontalLayout->setSpacing(6);
        mainHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        mainHorizontalLayout->setObjectName(QString("mainHorizontalLayout"));

        label = new QLabel(parent);
        label->setObjectName(QString("label"));
        label->setMaximumSize(QSize(250, 79));

        QFont font;
        font.setPointSize(15);
        font.setItalic(true);
        label->setFont(font);
        label->raise();

        mainHorizontalLayout->addWidget(label);

        optionsGroupBox = new QGroupBox(parent);
        optionsGroupBox->setObjectName(QString("optionsGroupBox"));
        optionsGroupBox->setMinimumSize(QSize(100, 80));
        optionsGroupBox->setMaximumSize(QSize(400, 300));
        mainHorizontalLayout->addWidget(optionsGroupBox);

        gridLayout = new QGridLayout(optionsGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString("gridLayout"));

        optionView1 = new QPushButton(optionsGroupBox);
        optionView1->setObjectName(QString("radioButton_View1"));

        optionView2 = new QPushButton(optionsGroupBox);
        optionView2->setObjectName(QString("radioButton_View2"));

        optionView3 = new QPushButton(optionsGroupBox);
        optionView3->setObjectName(QString("radioButton_View3"));

        optionView4 = new QPushButton(optionsGroupBox);
        optionView4->setObjectName(QString("radioButton_View4"));

        optionView5 = new QPushButton(optionsGroupBox);
        optionView5->setObjectName(QString("radioButton_View5"));

        optionView6 = new QPushButton(optionsGroupBox);
        optionView6->setObjectName(QString("radioButton_View6"));

        optionView1->setChecked(true);
        gridLayout->addWidget(optionView1, 0, 0);
        gridLayout->addWidget(optionView2, 0, 1);
        gridLayout->addWidget(optionView3, 0, 2);
        gridLayout->addWidget(optionView4, 1, 0);
        gridLayout->addWidget(optionView5, 1, 1);
        gridLayout->addWidget(optionView6, 1, 2);

        optionsGroupBox->setTitle(QApplication::translate("MainWindow", "Views", 0));
        optionView1->setText(QApplication::translate("MainWindow", "View1", 0));
        optionView2->setText(QApplication::translate("MainWindow", "View2", 0));
        optionView3->setText(QApplication::translate("MainWindow", "View3", 0));
        optionView4->setText(QApplication::translate("MainWindow", "View4", 0));
        optionView5->setText(QApplication::translate("MainWindow", "View5", 0));
        optionView6->setText(QApplication::translate("MainWindow", "View6", 0));
        label->setText(QApplication::translate("MainWindow", "Visualization Options", 0));

        connect(optionView1, SIGNAL(clicked()), this, SLOT(view1()));
        optionView1->setShortcut(QKeySequence("1"));
        connect(optionView2, SIGNAL(clicked()), this, SLOT(view2()));
        optionView1->setShortcut(QKeySequence("3"));
        connect(optionView3, SIGNAL(clicked()), this, SLOT(view3()));
        optionView1->setShortcut(QKeySequence("7"));
        connect(optionView4, SIGNAL(clicked()), this, SLOT(view4()));
        optionView1->setShortcut(QKeySequence("ctrl+1"));
        connect(optionView5, SIGNAL(clicked()), this, SLOT(view5()));
        optionView1->setShortcut(QKeySequence("ctrl+2"));
        connect(optionView6, SIGNAL(clicked()), this, SLOT(view6()));
        optionView1->setShortcut(QKeySequence("ctrl+7"));
    }

    ~OptionFrame() {}

    void setWidgetsLink( PaintingMesh *pme) {
        this->pme = pme;
    }

    void setCamera(CCamera* camera) {this->camera = camera;}

private slots:

    void view1()
    {
        this->camera->LookAt(1, 0, -10, 0, 1, 0, 0, 0, -10);
    }
    void view2()
    {
        this->camera->LookAt(0, 0, -11, 0, 1, 0, 0, 0, -10);
    }
    void view3()
    {
        this->camera->LookAt(0, 1, -10, 0, 1, 0, 0, 0, -10);
    }
    void view4()
    {
        this->camera->LookAt(-1, 0, -10, 0, 1, 0, 0, 0, -10);
    }
    void view5()
    {
        this->camera->LookAt(0, 0, -9, 0, 1, 0, 0, 0, -10);
    }
    void view6()
    {
        this->camera->LookAt(0, -1, -10, 0, 1, 0, 0, 0, -10);
    }
};

#endif // OPTIONFRAME_H

