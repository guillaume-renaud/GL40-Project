#ifndef OPTIONFRAME_H
#define OPTIONFRAME_H

#include <QMainWindow>
#include <QtGui>

#include <QWidget>

#include "paintingmesh.h"
#include "interactionframe.h"
#include <QGroupBox>
#include <QHeaderView>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <chrono>

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
    QTimer* timer;
    GLfloat focusX;
    GLfloat focusY;
    GLfloat dx;
    GLfloat dy;
    std::chrono::time_point<std::chrono::high_resolution_clock> time;
    InteractionFrame* interactionFrame;

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

        timer = new QTimer();

        connect(optionView1, SIGNAL(clicked()), this, SLOT(view1()));
        optionView1->setShortcut(QKeySequence("1"));
        connect(optionView2, SIGNAL(clicked()), this, SLOT(view2()));
        optionView2->setShortcut(QKeySequence("2"));
        connect(optionView3, SIGNAL(clicked()), this, SLOT(view3()));
        optionView3->setShortcut(QKeySequence("3"));
        connect(optionView4, SIGNAL(clicked()), this, SLOT(view4()));
        optionView4->setShortcut(QKeySequence("4"));
        connect(optionView5, SIGNAL(clicked()), this, SLOT(view5()));
        optionView5->setShortcut(QKeySequence("5"));
        connect(optionView6, SIGNAL(clicked()), this, SLOT(view6()));
        optionView6->setShortcut(QKeySequence("6"));
        connect(timer, SIGNAL(timeout()), this, SLOT(moveCamera()));
    }

    ~OptionFrame() {}

    void setWidgetsLink( PaintingMesh *pme) {
        this->pme = pme;
    }

    void setCamera(CCamera* camera) {this->camera = camera;}

    void translateOptionsGroupBox(char* txt)
    {
        optionsGroupBox->setTitle(QApplication::translate("MainWindow", txt, 0));
    }

    void translateOptionView1(char* txt, char* tooltip)
    {
        optionView1->setText(QApplication::translate("MainWindow", txt, 0));
        optionView1->setToolTip(tooltip);
    }

    void translateOptionView2(char* txt, char* tooltip)
    {
        optionView2->setText(QApplication::translate("MainWindow", txt, 0));
        optionView2->setToolTip(tooltip);
    }

    void translateOptionView3(char* txt, char* tooltip)
    {
        optionView3->setText(QApplication::translate("MainWindow", txt, 0));
        optionView3->setToolTip(tooltip);
    }

    void translateOptionView4(char* txt, char* tooltip)
    {
        optionView4->setText(QApplication::translate("MainWindow", txt, 0));
        optionView4->setToolTip(tooltip);
    }

    void translateOptionView5(char* txt, char* tooltip)
    {
        optionView5->setText(QApplication::translate("MainWindow", txt, 0));
        optionView5->setToolTip(tooltip);
    }

    void translateOptionView6(char* txt, char* tooltip)
    {
        optionView6->setText(QApplication::translate("MainWindow", txt, 0));
        optionView6->setToolTip(tooltip);
    }

    void translateLabel(char* txt)
    {
        label->setText(QApplication::translate("MainWindow", txt, 0));
    }

    void setInteractionFrame(InteractionFrame* interactionFrame)
    {
        this->interactionFrame = interactionFrame;
    }

private slots:

    void view1()
    {
        this->interactionFrame->getTimerTravling()->stop();
        this->time = std::chrono::high_resolution_clock::now();
        this->camera->init();
        this->focusX = 0.0f;
        this->focusY = 0.0f;
        this->dx = (this->focusX - this->camera->getRotatedX())/4.0f;
        this->dy = (this->focusY - this->camera->getRotatedY())/4.0f;
        this->timer->start();
    }
    void view2()
    {
        this->interactionFrame->getTimerTravling()->stop();
        this->time = std::chrono::high_resolution_clock::now();
        this->camera->init();
        this->focusX = 0.0f;
        this->focusY = 65.0f;
        this->dx = (this->focusX - this->camera->getRotatedX())/4.0f;
        this->dy = (this->focusY - this->camera->getRotatedY())/4.0f;
        this->timer->start();
    }
    void view3()
    {
        this->interactionFrame->getTimerTravling()->stop();
        this->time = std::chrono::high_resolution_clock::now();
        this->camera->init();
        this->focusX = -65.0f;
        this->focusY = 0.0f;
        this->dx = (this->focusX - this->camera->getRotatedX())/4.0f;
        this->dy = (this->focusY - this->camera->getRotatedY())/4.0f;
        this->timer->start();
    }
    void view4()
    {
        this->interactionFrame->getTimerTravling()->stop();
        this->time = std::chrono::high_resolution_clock::now();
        this->camera->init();
        this->focusX = 0.0f;
        this->focusY = 130.0f;
        this->dx = (this->focusX - this->camera->getRotatedX())/4.0f;
        this->dy = (this->focusY - this->camera->getRotatedY())/4.0f;
        this->timer->start();
    }
    void view5()
    {
        this->interactionFrame->getTimerTravling()->stop();
        this->time = std::chrono::high_resolution_clock::now();
        this->camera->init();
        this->focusX = 0.0f;
        this->focusY = -65.0f;
        this->dx = (this->focusX - this->camera->getRotatedX())/4.0f;
        this->dy = (this->focusY - this->camera->getRotatedY())/4.0f;
        this->timer->start();
    }
    void view6()
    {
        this->interactionFrame->getTimerTravling()->stop();
        this->time = std::chrono::high_resolution_clock::now();
        this->camera->init();
        this->focusX = 65.0f;
        this->focusY = 0.0f;
        this->dx = (this->focusX - this->camera->getRotatedX())/4.0f;
        this->dy = (this->focusY - this->camera->getRotatedY())/4.0f;
        this->timer->start();
    }

    void moveCamera()
    {
        if (std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::high_resolution_clock::now()-time).count() <= 500)
            return;
        this->camera->RotateObjectX(dx);
        if (this->focusX - 0.3 < this->camera->getRotatedX() && this->camera->getRotatedX() < this->focusX + 0.3)
        {
            this->camera->RotateObjectY(dy);

            if (this->focusY - 0.1 < this->camera->getRotatedY() && this->camera->getRotatedY() < this->focusY + 0.1)
                this->timer->stop();
        }
        this->camera->notify();
    }
};

#endif // OPTIONFRAME_H

