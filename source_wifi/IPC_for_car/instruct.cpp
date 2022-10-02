#include "instruct.h"
#include "ui_instruct.h"
#include "mainwindow.h"
#include <QMessageBox>
Instruct::Instruct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Instruct)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Configuration"));  //设置标题
    this->setWindowIcon(QIcon(":/Image/8315/m16.png"));

    //rectimer = new QTimer();//启动定时器
    //connect(rectimer,SIGNAL(timeout()),this,SLOT(rec_time_count()));//连接

}

Instruct::~Instruct()
{
    delete ui;
    INSTRCT_flag=false;
    qDebug()<<INSTRCT_flag;
}

void Instruct::on_btn_read_clicked()
{
    QByteArray temp;
    temp.append("H");
    emit Send_instruction(temp);
}

void Instruct::Receive_data(QByteArray temp)
{

    if(temp.contains("DONE")){
        QMessageBox::information(this, "TIP", "load success");
    }



    if(!temp.contains("\x1B[0m\r\n")){
        data.append(temp);
    }
    else{
        data.append(temp);

        data=data.right(data.length()-data.indexOf("\r\n")-2);
        QByteArray temp = data.left(data.indexOf("\r\n"));
        qDebug()<<"temp"<<temp;
        if((temp=="0"||temp=="1"||temp=="2"||temp=="3")&&temp.size()==1){
            ui->line_mode->setText(QString(temp));
            data=data.right(data.length()-data.indexOf("\r\n")-2);
            temp = data.left(data.indexOf("\r\n"));
            ui->line_baud->setText(QString(temp));

            data=data.right(data.length()-data.indexOf("\r\n")-2);
            temp = data.left(data.indexOf("\r\n"));
            ui->line_size->setText(QString(temp));

            data=data.right(data.length()-data.indexOf("\r\n")-2);
            temp = data.left(data.indexOf("\r\n"));
            ui->line_name->setText(QString(temp));

            data=data.right(data.length()-data.indexOf("\r\n")-2);
            temp = data.left(data.indexOf("\r\n"));
            ui->line_code->setText(QString(temp));

            data=data.right(data.length()-data.indexOf("\r\n")-2);
            temp = data.left(data.indexOf("\r\n"));
            ui->line_address->setText(QString(temp));

            data=data.right(data.length()-data.indexOf("\r\n")-2);
            temp = data.left(data.indexOf("\r\n"));
            ui->line_com->setText(QString(temp));


        }
        data.clear();
    }



}


void Instruct::on_btn_load_clicked()
{
    QByteArray load;
    load.append("I");
    emit Send_instruction(load);
}





void Instruct::on_btn_write_mode_clicked()
{
    QByteArray temp;
    temp.append("A");
    temp.append(ui->line_mode->text().toInt());
    emit Send_instruction(temp);
}



void Instruct::on_btn_write_baud_clicked()
{
    QByteArray temp;
    temp.append("B");
    int tempbuf = ui->line_baud->text().toInt();
    temp.append(tempbuf>>24);
    temp.append(tempbuf>>16);
    temp.append(tempbuf>>8);
    temp.append(tempbuf);



    emit Send_instruction(temp);
}

void Instruct::on_btn_write_size_clicked()
{
    QByteArray temp;
    temp.append("C");
    int tempbuf = ui->line_size->text().toInt();
    temp.append(tempbuf>>8);
    temp.append(tempbuf);
    emit Send_instruction(temp);
}

void Instruct::on_btn_write_name_clicked()
{
    QByteArray temp;
    temp.append("D");
    temp.append(ui->line_name->text().toUtf8());
    emit Send_instruction(temp);

}


void Instruct::on_btn_write_code_clicked()
{
    QByteArray temp;
    temp.append("E");
    temp.append(ui->line_code->text().toUtf8());
    emit Send_instruction(temp);
}

void Instruct::on_btn_write_address_clicked()
{
    QByteArray temp;
    temp.append("F");
    temp.append(ui->line_address->text().toUtf8());
    emit Send_instruction(temp);
}



void Instruct::on_btn_write_com_clicked()
{
    QByteArray temp;
    temp.append("G");
    int tempbuf = ui->line_com->text().toInt();
    temp.append(tempbuf>>8);
    temp.append(tempbuf);
    emit Send_instruction(temp);
}

void Instruct::rec_time_count()
{

}
