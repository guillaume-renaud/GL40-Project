#ifndef INTERACTIONFRAME
#define INTERACTIONFRAME

#include <QMainWindow>
#include <QtGui>

#include <QWidget>

#include "paintingmesh.h"
#include <QGroupBox>
#include <QHeaderView>
#include <QRadioButton>
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QPushButton>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QRadioButton;
QT_END_NAMESPACE

class InteractionFrame : public QWidget, public Observable
{
    Q_OBJECT

private:

    QTimer* timer;
    QLabel *label;
    PaintingMesh *pme;
    QVBoxLayout *mainVerticalLayout;
    QPushButton *startTimer, *stopTimer;

    CCamera* camera;

public:
    explicit InteractionFrame(QFrame *parent = 0)
    {
        timer = new QTimer();

        mainVerticalLayout = new QVBoxLayout(parent);
        mainVerticalLayout->setSpacing(6);
        mainVerticalLayout->setContentsMargins(11, 11, 11, 11);
        mainVerticalLayout->setObjectName(QString("mainVerticalLayout"));

        label = new QLabel(parent);
        label->setObjectName(QString("label"));
        label->setMaximumSize(QSize(250, 79));

        QFont font;
        font.setPointSize(15);
        font.setItalic(true);
        label->setFont(font);
        label->raise();

        mainVerticalLayout->addWidget(label);

        startTimer = new QPushButton("Start traveling");
        stopTimer = new QPushButton("Stop traveling");

        mainVerticalLayout->addWidget(startTimer);
        mainVerticalLayout->addWidget(stopTimer);

        connect(startTimer, SIGNAL(clicked()), this, SLOT(startTraveling()));
        connect(stopTimer, SIGNAL(clicked()), this, SLOT(stopTraveling()));
        connect(timer, SIGNAL(timeout()), this, SLOT(traveling()));
    }

    ~InteractionFrame() {}

    void setWidgetsLink( PaintingMesh *pme) {
        this->pme = pme;
    }

    void translateLabel(char* txt)
    {
        label->setText(QApplication::translate("MainWindow", txt, 0));
    }

    void setCamera(CCamera* camera){
        this->camera = camera;
    }

    QTimer* getTimerTravling()
    {
        return this->timer;
    }

private slots :
    void startTraveling()
    {
        timer->start();
    }

    void stopTraveling()
    {
        timer->stop();
    }

    void traveling()
    {
        this->camera->RotateObjectY(5);
        notify();
    }
};


#endif // INTERACTIONFRAME

