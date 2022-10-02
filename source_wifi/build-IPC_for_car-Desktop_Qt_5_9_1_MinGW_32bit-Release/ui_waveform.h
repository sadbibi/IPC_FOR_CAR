/********************************************************************************
** Form generated from reading UI file 'waveform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFORM_H
#define UI_WAVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_WaveForm
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCustomPlot *widget_plot;
    QPushButton *btnexit;
    QLabel *label;
    QLineEdit *line_pra1;
    QLabel *label_2;
    QLineEdit *line_pra2;

    void setupUi(QWidget *WaveForm)
    {
        if (WaveForm->objectName().isEmpty())
            WaveForm->setObjectName(QStringLiteral("WaveForm"));
        WaveForm->resize(768, 466);
        groupBox = new QGroupBox(WaveForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(170, 20, 581, 401));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget_plot = new QCustomPlot(groupBox);
        widget_plot->setObjectName(QStringLiteral("widget_plot"));

        gridLayout_2->addWidget(widget_plot, 0, 0, 1, 1);

        btnexit = new QPushButton(WaveForm);
        btnexit->setObjectName(QStringLiteral("btnexit"));
        btnexit->setGeometry(QRect(660, 430, 93, 28));
        label = new QLabel(WaveForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 72, 15));
        line_pra1 = new QLineEdit(WaveForm);
        line_pra1->setObjectName(QStringLiteral("line_pra1"));
        line_pra1->setGeometry(QRect(20, 50, 113, 21));
        label_2 = new QLabel(WaveForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 72, 15));
        line_pra2 = new QLineEdit(WaveForm);
        line_pra2->setObjectName(QStringLiteral("line_pra2"));
        line_pra2->setGeometry(QRect(20, 120, 113, 21));

        retranslateUi(WaveForm);
        QObject::connect(btnexit, SIGNAL(clicked()), WaveForm, SLOT(close()));

        QMetaObject::connectSlotsByName(WaveForm);
    } // setupUi

    void retranslateUi(QWidget *WaveForm)
    {
        WaveForm->setWindowTitle(QApplication::translate("WaveForm", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("WaveForm", "\345\256\236\346\227\266\346\233\262\347\272\277\346\230\276\347\244\272", Q_NULLPTR));
        btnexit->setText(QApplication::translate("WaveForm", "exit", Q_NULLPTR));
        label->setText(QApplication::translate("WaveForm", "\345\217\202\346\225\2601", Q_NULLPTR));
        label_2->setText(QApplication::translate("WaveForm", "\345\217\202\346\225\2602", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WaveForm: public Ui_WaveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFORM_H
