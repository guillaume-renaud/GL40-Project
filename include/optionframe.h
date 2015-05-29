#ifndef OPTIONFRAME_H
#define OPTIONFRAME_H

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

class OptionFrame : public QWidget
{
    Q_OBJECT

private:

    QLabel *label;
    PaintingMesh *pme;
    QHBoxLayout *mainHorizontalLayout;
    QGroupBox *optionsGroupBox;
    QGridLayout *gridLayout;
    QRadioButton *optionView1, *optionView2, *optionView3, *optionView4, *optionView5, *optionView6;

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
        optionsGroupBox->setMaximumSize(QSize(260, 200));
        mainHorizontalLayout->addWidget(optionsGroupBox);

        gridLayout = new QGridLayout(optionsGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString("gridLayout"));

        optionView1 = new QRadioButton(optionsGroupBox);
        optionView1->setObjectName(QString("radioButton_View1"));
        optionView1->setGeometry(QRect(30, 30, 117, 22));

        optionView2 = new QRadioButton(optionsGroupBox);
        optionView2->setObjectName(QString("radioButton_View2"));
        optionView2->setGeometry(QRect(30, 60, 117, 22));

        optionView3 = new QRadioButton(optionsGroupBox);
        optionView3->setObjectName(QString("radioButton_View3"));
        optionView3->setGeometry(QRect(230, 30, 117, 22));

        optionView4 = new QRadioButton(optionsGroupBox);
        optionView4->setObjectName(QString("radioButton_View4"));
        optionView4->setGeometry(QRect(230, 60, 117, 22));

        optionView5 = new QRadioButton(optionsGroupBox);
        optionView5->setObjectName(QString("radioButton_View5"));
        optionView5->setGeometry(QRect(230, 30, 117, 22));

        optionView6 = new QRadioButton(optionsGroupBox);
        optionView6->setObjectName(QString("radioButton_View6"));
        optionView6->setGeometry(QRect(230, 60, 117, 22));

        optionView1->setChecked(true);
        gridLayout->addWidget(optionView1, 0, 0, 1, 2);
        gridLayout->addWidget(optionView2, 0, 1, 1, 2);
        gridLayout->addWidget(optionView3, 0, 2, 1, 1);
        gridLayout->addWidget(optionView4, 1, 0, 1, 2);
        gridLayout->addWidget(optionView5, 1, 1, 1, 2);
        gridLayout->addWidget(optionView6, 1, 2, 1, 1);

        optionsGroupBox->setTitle(QApplication::translate("MainWindow", "Views", 0));
        optionView1->setText(QApplication::translate("MainWindow", "View1", 0));
        optionView2->setText(QApplication::translate("MainWindow", "View2", 0));
        optionView3->setText(QApplication::translate("MainWindow", "View3", 0));
        optionView4->setText(QApplication::translate("MainWindow", "View4", 0));
        optionView5->setText(QApplication::translate("MainWindow", "View5", 0));
        optionView6->setText(QApplication::translate("MainWindow", "View6", 0));
        label->setText(QApplication::translate("MainWindow", "Visualization Options", 0));

    }

    ~OptionFrame() {}

    void setWidgetsLink( PaintingMesh *pme) {
        this->pme = pme;
    }
};

#endif // OPTIONFRAME_H

