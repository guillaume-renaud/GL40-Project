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

class InteractionFrame : public QWidget
{
    Q_OBJECT

private:

    QTimer* timer;
    QLabel *label;
    PaintingMesh *pme;
    QVBoxLayout *mainVerticalLayout;
    QPushButton *startTimer, *stopTimer;

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

        startTimer = new QPushButton();
        stopTimer = new QPushButton();

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

    void translateStartTimer(char* txt)
    {
        startTimer->setText(QApplication::translate("MainWindow", txt, 0));
    }
    void translateStopTimer(char* txt)
    {
        stopTimer->setText(QApplication::translate("MainWindow", txt, 0));
    }


private slots :
    void startTraveling()
    {
        timer->start();
    }

    void stopTraveling()
    {
        timer->stop();
        qDebug() << "je travel plus !";
    }

    void traveling()
    {
        qDebug() << "je traveeeeeelllllll !";
    }
};


#endif // INTERACTIONFRAME

