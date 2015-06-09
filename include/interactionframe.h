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

QT_BEGIN_NAMESPACE
class QGroupBox;
class QRadioButton;
QT_END_NAMESPACE

class InteractionFrame : public QWidget
{
    Q_OBJECT

private:

    QLabel *label;
    PaintingMesh *pme;
    QVBoxLayout *mainVerticalLayout;

public:
    explicit InteractionFrame(QFrame *parent = 0)
    {
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
    }

    ~InteractionFrame() {}

    void setWidgetsLink( PaintingMesh *pme) {
        this->pme = pme;
    }

    void translateLabel(char* txt)
    {
        label->setText(QApplication::translate("MainWindow", txt, 0));
    }

};


#endif // INTERACTIONFRAME

