#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Help"));  //设置标题
    this->setWindowIcon(QIcon(":/Image/8315/m16.png"));
}

Help::~Help()
{
    delete ui;
}
