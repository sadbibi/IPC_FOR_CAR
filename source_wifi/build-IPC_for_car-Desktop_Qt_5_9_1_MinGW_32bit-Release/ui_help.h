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
        Help->resize(584, 368);
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
        plainTextEdit->setPlainText(QApplication::translate("Help", "\350\207\264\347\224\250\345\233\276\344\274\240\344\270\212\344\275\215\346\234\272\345\274\200\345\217\221\350\200\205\357\274\232\345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\n"
"\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232\n"
"QQ\357\274\232    1486148289\n"
"WECHAT\357\274\23215973154347\n"
"\351\227\262\351\261\274ID\357\274\232\345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\n"
"B\347\253\231ID\357\274\232 \345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\n"
"\346\267\230\345\256\235\345\272\227\351\223\272ID\357\274\232\345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\n"
"\n"
"PIC-O-LINK\345\274\200\345\217\221\350\200\205\357\274\232\345\215\234\346\236\227\n"
"QQ\357\274\2321626632460\n"
"\n"
"PIC-O-LINK\345\222\214\350\207\264\347\224\250\345\233\276\344\274\240\351\234\200\350\246\201\351\205\215\345\245\227\344\275\277\347\224\250\357\274\214PIC-O-LINK\345\234\250\346\267\230\345\256\235\345\272\227\345\222\214\351\227\262\351\261\274"
                        "\345\272\227\345\235\207\346\234\211\345\207\272\345\224\256\357\274\214\351\234\200\350\246\201\350\257\267\350\256\244\345\207\206\345\272\227\351\223\272\345\220\215\357\274\232\345\267\246\345\256\266\345\236\205\347\232\204\347\211\233\343\200\202\n"
"\n"
"\344\275\277\347\224\250\346\225\231\347\250\213\345\234\250\350\264\255\344\271\260\344\272\247\345\223\201\344\271\213\345\220\216\350\201\224\347\263\273\345\256\242\346\234\215\350\216\267\345\217\226\343\200\202\n"
"\n"
"\345\274\200\345\217\221\344\270\215\346\230\223\357\274\214\347\246\201\346\255\242\345\200\222\345\215\226\343\200\202\n"
"\n"
"\345\220\214\346\227\266\346\210\221\344\273\254\346\217\220\344\276\233\346\231\272\350\203\275\350\275\246\346\257\224\350\265\233\347\232\204\346\214\207\345\257\274\346\234\215\345\212\241\357\274\214\346\234\211\351\234\200\350\246\201\345\217\257\344\273\245\346\267\230\345\256\235\346\210\226\351\227\262\351\261\274\350\201\224\347\263\273\357\274\201\357\274\201\n"
"", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
