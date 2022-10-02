/********************************************************************************
** Form generated from reading UI file 'instruct.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCT_H
#define UI_INSTRUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Instruct
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QTextEdit *textEdit;

    void setupUi(QWidget *Instruct)
    {
        if (Instruct->objectName().isEmpty())
            Instruct->setObjectName(QStringLiteral("Instruct"));
        Instruct->resize(602, 384);
        gridLayout_3 = new QGridLayout(Instruct);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Instruct);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(Instruct);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(Instruct);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        label_2 = new QLabel(Instruct);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(Instruct);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(Instruct);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        label_3 = new QLabel(Instruct);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(Instruct);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(Instruct);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(Instruct);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        textEdit = new QTextEdit(Instruct);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(Instruct);

        QMetaObject::connectSlotsByName(Instruct);
    } // setupUi

    void retranslateUi(QWidget *Instruct)
    {
        Instruct->setWindowTitle(QApplication::translate("Instruct", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Instruct", "P", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Instruct", "SEND", Q_NULLPTR));
        label_2->setText(QApplication::translate("Instruct", "I", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Instruct", "SEDN", Q_NULLPTR));
        label_3->setText(QApplication::translate("Instruct", "D", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Instruct", "SEND", Q_NULLPTR));
        label_4->setText(QApplication::translate("Instruct", "\346\216\245\346\224\266\346\241\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Instruct: public Ui_Instruct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCT_H
