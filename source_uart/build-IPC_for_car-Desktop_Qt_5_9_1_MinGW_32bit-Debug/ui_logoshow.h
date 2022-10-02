/********************************************************************************
** Form generated from reading UI file 'logoshow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOSHOW_H
#define UI_LOGOSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logoshow
{
public:

    void setupUi(QWidget *Logoshow)
    {
        if (Logoshow->objectName().isEmpty())
            Logoshow->setObjectName(QStringLiteral("Logoshow"));
        Logoshow->resize(400, 300);

        retranslateUi(Logoshow);

        QMetaObject::connectSlotsByName(Logoshow);
    } // setupUi

    void retranslateUi(QWidget *Logoshow)
    {
        Logoshow->setWindowTitle(QApplication::translate("Logoshow", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Logoshow: public Ui_Logoshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOSHOW_H
