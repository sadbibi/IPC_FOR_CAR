/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionimage;
    QAction *actionwave;
    QAction *actioninstruct;
    QAction *actionhelp;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_seacher;
    QComboBox *com_choose;
    QPushButton *btn_open;
    QLabel *label;
    QComboBox *box_baud;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *imagbar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 719);
        actionimage = new QAction(MainWindow);
        actionimage->setObjectName(QStringLiteral("actionimage"));
        actionimage->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/8315/m5.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/image/8315/m5.ico"), QSize(), QIcon::Normal, QIcon::On);
        actionimage->setIcon(icon);
        actionwave = new QAction(MainWindow);
        actionwave->setObjectName(QStringLiteral("actionwave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/8315/m7.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionwave->setIcon(icon1);
        actionwave->setShortcutContext(Qt::WidgetWithChildrenShortcut);
        actioninstruct = new QAction(MainWindow);
        actioninstruct->setObjectName(QStringLiteral("actioninstruct"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/8315/m10.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actioninstruct->setIcon(icon2);
        actionhelp = new QAction(MainWindow);
        actionhelp->setObjectName(QStringLiteral("actionhelp"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/8315/m9.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionhelp->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_seacher = new QPushButton(centralWidget);
        btn_seacher->setObjectName(QStringLiteral("btn_seacher"));

        horizontalLayout->addWidget(btn_seacher);

        com_choose = new QComboBox(centralWidget);
        com_choose->setObjectName(QStringLiteral("com_choose"));

        horizontalLayout->addWidget(com_choose);

        btn_open = new QPushButton(centralWidget);
        btn_open->setObjectName(QStringLiteral("btn_open"));

        horizontalLayout->addWidget(btn_open);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        box_baud = new QComboBox(centralWidget);
        box_baud->setObjectName(QStringLiteral("box_baud"));

        horizontalLayout->addWidget(box_baud);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(238, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 26));
        imagbar = new QMenu(menuBar);
        imagbar->setObjectName(QStringLiteral("imagbar"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(160, 40));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(imagbar->menuAction());
        mainToolBar->addAction(actionimage);
        mainToolBar->addAction(actionwave);
        mainToolBar->addAction(actioninstruct);
        mainToolBar->addAction(actionhelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionimage->setText(QApplication::translate("MainWindow", "\345\233\276\344\274\240", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionimage->setToolTip(QApplication::translate("MainWindow", "image", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionwave->setText(QApplication::translate("MainWindow", "\347\244\272\346\263\242\345\231\250", Q_NULLPTR));
        actioninstruct->setText(QApplication::translate("MainWindow", "\346\214\207\344\273\244\345\231\250", Q_NULLPTR));
        actionhelp->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        btn_seacher->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242\344\270\262\345\217\243", Q_NULLPTR));
        btn_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        box_baud->clear();
        box_baud->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "4800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "460800", Q_NULLPTR)
        );
        imagbar->setTitle(QApplication::translate("MainWindow", "\344\270\212\344\275\215\346\234\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
