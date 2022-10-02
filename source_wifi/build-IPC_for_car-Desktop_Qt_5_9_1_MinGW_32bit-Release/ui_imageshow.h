/********************************************************************************
** Form generated from reading UI file 'imageshow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESHOW_H
#define UI_IMAGESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <mouseevent.h>

QT_BEGIN_NAMESPACE

class Ui_imageshow
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_imagesave;
    QPushButton *btn_imageread;
    QPushButton *btn_videosave;
    QPushButton *btn_videoread;
    QPushButton *btn_videoshow;
    QCheckBox *checkBox;
    QCheckBox *Pic_01_check;
    QLabel *label_2;
    QSpinBox *spinBox_height;
    QLabel *label_3;
    QSpinBox *spinBox_width;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    MouseEvent *imaglabel;
    QHBoxLayout *horizontalLayout_4;
    QSlider *PicSlider;
    QLabel *Piclabel;
    QPushButton *btn_atlas;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *line_bufsize;
    QLabel *label_4;
    QLineEdit *line_picT;

    void setupUi(QWidget *imageshow)
    {
        if (imageshow->objectName().isEmpty())
            imageshow->setObjectName(QStringLiteral("imageshow"));
        imageshow->resize(963, 521);
        gridLayout_2 = new QGridLayout(imageshow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_imagesave = new QPushButton(imageshow);
        btn_imagesave->setObjectName(QStringLiteral("btn_imagesave"));
        btn_imagesave->setCheckable(false);

        horizontalLayout->addWidget(btn_imagesave);

        btn_imageread = new QPushButton(imageshow);
        btn_imageread->setObjectName(QStringLiteral("btn_imageread"));

        horizontalLayout->addWidget(btn_imageread);

        btn_videosave = new QPushButton(imageshow);
        btn_videosave->setObjectName(QStringLiteral("btn_videosave"));

        horizontalLayout->addWidget(btn_videosave);

        btn_videoread = new QPushButton(imageshow);
        btn_videoread->setObjectName(QStringLiteral("btn_videoread"));

        horizontalLayout->addWidget(btn_videoread);

        btn_videoshow = new QPushButton(imageshow);
        btn_videoshow->setObjectName(QStringLiteral("btn_videoshow"));

        horizontalLayout->addWidget(btn_videoshow);


        horizontalLayout_2->addLayout(horizontalLayout);

        checkBox = new QCheckBox(imageshow);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        Pic_01_check = new QCheckBox(imageshow);
        Pic_01_check->setObjectName(QStringLiteral("Pic_01_check"));

        horizontalLayout_2->addWidget(Pic_01_check);

        label_2 = new QLabel(imageshow);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_height = new QSpinBox(imageshow);
        spinBox_height->setObjectName(QStringLiteral("spinBox_height"));
        spinBox_height->setMaximum(480);
        spinBox_height->setValue(60);

        horizontalLayout_2->addWidget(spinBox_height);

        label_3 = new QLabel(imageshow);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBox_width = new QSpinBox(imageshow);
        spinBox_width->setObjectName(QStringLiteral("spinBox_width"));
        spinBox_width->setMaximum(480);
        spinBox_width->setValue(80);

        horizontalLayout_2->addWidget(spinBox_width);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        scrollArea = new QScrollArea(imageshow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 939, 392));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        imaglabel = new MouseEvent(scrollAreaWidgetContents);
        imaglabel->setObjectName(QStringLiteral("imaglabel"));

        gridLayout->addWidget(imaglabel, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        PicSlider = new QSlider(imageshow);
        PicSlider->setObjectName(QStringLiteral("PicSlider"));
        PicSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(PicSlider);

        Piclabel = new QLabel(imageshow);
        Piclabel->setObjectName(QStringLiteral("Piclabel"));

        horizontalLayout_4->addWidget(Piclabel);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 2);

        btn_atlas = new QPushButton(imageshow);
        btn_atlas->setObjectName(QStringLiteral("btn_atlas"));

        gridLayout_2->addWidget(btn_atlas, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(198, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(imageshow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        line_bufsize = new QLineEdit(imageshow);
        line_bufsize->setObjectName(QStringLiteral("line_bufsize"));

        horizontalLayout_3->addWidget(line_bufsize);

        label_4 = new QLabel(imageshow);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        line_picT = new QLineEdit(imageshow);
        line_picT->setObjectName(QStringLiteral("line_picT"));

        horizontalLayout_3->addWidget(line_picT);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 1, 1, 1);


        retranslateUi(imageshow);

        QMetaObject::connectSlotsByName(imageshow);
    } // setupUi

    void retranslateUi(QWidget *imageshow)
    {
        imageshow->setWindowTitle(QApplication::translate("imageshow", "Form", Q_NULLPTR));
        btn_imagesave->setText(QApplication::translate("imageshow", "\344\277\235\345\255\230\345\233\276\347\211\207", Q_NULLPTR));
        btn_imageread->setText(QApplication::translate("imageshow", "\345\257\274\345\205\245\345\233\276\347\211\207", Q_NULLPTR));
        btn_videosave->setText(QApplication::translate("imageshow", "\345\257\274\345\207\272\350\247\206\351\242\221", Q_NULLPTR));
        btn_videoread->setText(QApplication::translate("imageshow", "\345\257\274\345\205\245\350\247\206\351\242\221", Q_NULLPTR));
        btn_videoshow->setText(QApplication::translate("imageshow", "\345\274\200\345\247\213\346\222\255\346\224\276", Q_NULLPTR));
        checkBox->setText(QApplication::translate("imageshow", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR));
        Pic_01_check->setText(QApplication::translate("imageshow", "\344\272\214\345\200\274\345\233\276\357\274\210\345\270\246\350\276\271\347\225\214\357\274\211", Q_NULLPTR));
        label_2->setText(QApplication::translate("imageshow", "\351\253\230\345\272\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("imageshow", "\345\256\275\345\272\246", Q_NULLPTR));
        imaglabel->setText(QString());
        Piclabel->setText(QApplication::translate("imageshow", "0", Q_NULLPTR));
        btn_atlas->setText(QApplication::translate("imageshow", "\351\200\211\346\213\251\346\222\255\346\224\276\345\233\276\347\211\207\351\233\206", Q_NULLPTR));
        label->setText(QApplication::translate("imageshow", "\345\255\227\350\212\202\346\225\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("imageshow", "\345\221\250\346\234\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class imageshow: public Ui_imageshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESHOW_H
