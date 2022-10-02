/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QStringLiteral("Help"));
        Help->resize(497, 325);
        gridLayout = new QGridLayout(Help);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plainTextEdit = new QPlainTextEdit(Help);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 0, 0, 1, 1);


        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QWidget *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Form", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("Help", "\345\274\200\345\217\221\350\200\205\357\274\232\345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\n"
"\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232\n"
"QQ\357\274\232    1486148289\n"
"WECHAT\357\274\23215973154347\n"
"\351\227\262\351\261\274ID\357\274\232\345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\n"
"B\347\253\231ID\357\274\232 \345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\n"
"\345\246\202\346\234\211\351\234\200\350\246\201\346\231\272\350\203\275\350\275\246\346\214\207\345\257\274\346\210\226\350\200\205\344\270\212\344\275\215\346\234\272\346\272\220\347\240\201\345\217\212\345\205\266\344\275\277\347\224\250\346\225\231\347\250\213\357\274\214\350\257\267\345\234\250\351\227\262\351\261\274\346\211\276\346\210\221\343\200\202\n"
"\n"
"\346\234\254\344\270\212\344\275\215\346\234\272\344\270\255\347\232\204\344\270\273\350\246\201\344\270\272\344\272\206\346\234\254\346\240\241\345\217\212\345\205\266\345\234\250\346\210\221\344\270\213\351\235\242"
                        "\346\216\245\345\217\227\346\214\207\345\257\274\345\255\246\345\221\230\346\217\220\344\276\233\345\233\276\345\203\217\346\225\231\n"
"\345\255\246\357\274\214\345\217\212\345\205\266\350\276\205\345\212\251\350\260\203\350\257\225\346\226\271\345\274\217\343\200\202\345\246\202\346\236\234\345\270\214\346\234\233\346\212\212\351\207\214\351\235\242\347\232\204\345\233\276\345\203\217\345\244\204\347\220\206\346\230\257\350\207\252\345\267\261\347\232\204\347\256\227\346\263\225\n"
"\350\257\267\350\207\252\350\241\214\345\234\250\346\272\220\347\240\201\344\270\255\347\247\273\346\244\215\357\274\201\n"
"\n"
"\347\224\261\344\272\216\346\234\254\350\275\257\344\273\266\345\274\200\346\272\220\357\274\214\344\270\215\345\256\232\346\234\237\347\273\264\346\212\244\357\274\214\346\234\211\351\227\256\351\242\230\350\257\267\345\217\221\350\207\263QQ\351\202\256\347\256\261\357\274\214\346\234\211\347\251\272\347\273\264\346\212\244\346\233\264\346\226\260\357\274\201\357\274\201\357\274\201\357\274\201\n"
"\n"
"", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
