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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Instruct
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_mode;
    QPushButton *btn_write_mode;
    QLabel *label_2;
    QLineEdit *line_baud;
    QPushButton *btn_write_baud;
    QLabel *label_3;
    QLineEdit *line_size;
    QPushButton *btn_write_size;
    QLabel *label_4;
    QLineEdit *line_name;
    QPushButton *btn_write_name;
    QLabel *label_5;
    QLineEdit *line_code;
    QPushButton *btn_write_code;
    QLabel *label_6;
    QLineEdit *line_address;
    QPushButton *btn_write_address;
    QLabel *label_7;
    QLineEdit *line_com;
    QPushButton *btn_write_com;
    QPushButton *btn_read;
    QPushButton *btn_load;

    void setupUi(QWidget *Instruct)
    {
        if (Instruct->objectName().isEmpty())
            Instruct->setObjectName(QStringLiteral("Instruct"));
        Instruct->resize(397, 398);
        gridLayout = new QGridLayout(Instruct);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Instruct);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_mode = new QLineEdit(Instruct);
        line_mode->setObjectName(QStringLiteral("line_mode"));

        gridLayout->addWidget(line_mode, 0, 1, 1, 2);

        btn_write_mode = new QPushButton(Instruct);
        btn_write_mode->setObjectName(QStringLiteral("btn_write_mode"));

        gridLayout->addWidget(btn_write_mode, 0, 3, 1, 1);

        label_2 = new QLabel(Instruct);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        line_baud = new QLineEdit(Instruct);
        line_baud->setObjectName(QStringLiteral("line_baud"));

        gridLayout->addWidget(line_baud, 1, 1, 1, 2);

        btn_write_baud = new QPushButton(Instruct);
        btn_write_baud->setObjectName(QStringLiteral("btn_write_baud"));

        gridLayout->addWidget(btn_write_baud, 1, 3, 1, 1);

        label_3 = new QLabel(Instruct);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        line_size = new QLineEdit(Instruct);
        line_size->setObjectName(QStringLiteral("line_size"));

        gridLayout->addWidget(line_size, 2, 1, 1, 2);

        btn_write_size = new QPushButton(Instruct);
        btn_write_size->setObjectName(QStringLiteral("btn_write_size"));

        gridLayout->addWidget(btn_write_size, 2, 3, 1, 1);

        label_4 = new QLabel(Instruct);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        line_name = new QLineEdit(Instruct);
        line_name->setObjectName(QStringLiteral("line_name"));

        gridLayout->addWidget(line_name, 3, 1, 1, 2);

        btn_write_name = new QPushButton(Instruct);
        btn_write_name->setObjectName(QStringLiteral("btn_write_name"));

        gridLayout->addWidget(btn_write_name, 3, 3, 1, 1);

        label_5 = new QLabel(Instruct);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        line_code = new QLineEdit(Instruct);
        line_code->setObjectName(QStringLiteral("line_code"));

        gridLayout->addWidget(line_code, 4, 1, 1, 2);

        btn_write_code = new QPushButton(Instruct);
        btn_write_code->setObjectName(QStringLiteral("btn_write_code"));

        gridLayout->addWidget(btn_write_code, 4, 3, 1, 1);

        label_6 = new QLabel(Instruct);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        line_address = new QLineEdit(Instruct);
        line_address->setObjectName(QStringLiteral("line_address"));

        gridLayout->addWidget(line_address, 5, 1, 1, 2);

        btn_write_address = new QPushButton(Instruct);
        btn_write_address->setObjectName(QStringLiteral("btn_write_address"));

        gridLayout->addWidget(btn_write_address, 5, 3, 1, 1);

        label_7 = new QLabel(Instruct);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        line_com = new QLineEdit(Instruct);
        line_com->setObjectName(QStringLiteral("line_com"));

        gridLayout->addWidget(line_com, 6, 1, 1, 2);

        btn_write_com = new QPushButton(Instruct);
        btn_write_com->setObjectName(QStringLiteral("btn_write_com"));

        gridLayout->addWidget(btn_write_com, 6, 3, 1, 1);

        btn_read = new QPushButton(Instruct);
        btn_read->setObjectName(QStringLiteral("btn_read"));

        gridLayout->addWidget(btn_read, 7, 1, 1, 1);

        btn_load = new QPushButton(Instruct);
        btn_load->setObjectName(QStringLiteral("btn_load"));

        gridLayout->addWidget(btn_load, 7, 2, 1, 2);


        retranslateUi(Instruct);

        QMetaObject::connectSlotsByName(Instruct);
    } // setupUi

    void retranslateUi(QWidget *Instruct)
    {
        Instruct->setWindowTitle(QApplication::translate("Instruct", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Instruct", "\346\250\241\345\274\217", Q_NULLPTR));
        btn_write_mode->setText(QApplication::translate("Instruct", "\351\205\215\347\275\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("Instruct", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        btn_write_baud->setText(QApplication::translate("Instruct", "\351\205\215\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("Instruct", "\345\255\227\350\212\202\346\225\260", Q_NULLPTR));
        btn_write_size->setText(QApplication::translate("Instruct", "\351\205\215\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("Instruct", "\347\275\221\347\273\234\345\220\215\347\247\260", Q_NULLPTR));
        btn_write_name->setText(QApplication::translate("Instruct", "\351\205\215\347\275\256", Q_NULLPTR));
        label_5->setText(QApplication::translate("Instruct", "\347\275\221\347\273\234\345\257\206\347\240\201", Q_NULLPTR));
        btn_write_code->setText(QApplication::translate("Instruct", "\351\205\215\347\275\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("Instruct", "\347\275\221\347\273\234\345\234\260\345\235\200", Q_NULLPTR));
        btn_write_address->setText(QApplication::translate("Instruct", "\351\205\215\347\275\256", Q_NULLPTR));
        label_7->setText(QApplication::translate("Instruct", "\347\275\221\347\273\234\347\253\257\345\217\243", Q_NULLPTR));
        btn_write_com->setText(QApplication::translate("Instruct", "\351\205\215\347\275\256", Q_NULLPTR));
        btn_read->setText(QApplication::translate("Instruct", "\350\257\273\345\217\226", Q_NULLPTR));
        btn_load->setText(QApplication::translate("Instruct", "\344\270\213\350\275\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Instruct: public Ui_Instruct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCT_H
