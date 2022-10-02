#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <serialworker.h>
#include "imageshow.h"
#include "waveform.h"
#include <QDebug>
#include <QLabel>
#include <QPoint>
QString IPADRRS;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("致用图传上位机"));  //设置标题
    this->setWindowIcon(QIcon(":/Image/8315/m16.png"));
    myserial = new QSerialPort;
    timer = new QTimer();
    ui->menuBar->setVisible(false);



/*************线程***************/
    // 1.新建串口处理子线程
    SerialWorker *serialWorker = new SerialWorker(myserial);
    serialWorker->moveToThread(&chithread);
    // 2.连接信号和槽
    connect(&chithread, &QThread::finished,
            serialWorker, &QObject::deleteLater);           // 线程结束，自动删除对象
    connect(this, &MainWindow::serialDataSend,
            serialWorker, &SerialWorker::doDataSendWork);   // 主线程串口数据发送的信号
    connect(myserial, &QSerialPort::readyRead,
            serialWorker, &SerialWorker::doDataReciveWork);
    connect(serialWorker, &SerialWorker::sendResultToGui,
            this, &MainWindow::handleResults);              // 主线程收到数据结果的信号
    SIREAL_flag = false;
    // 3.开始运行子线程
    chithread.start();                   // 线程开始运行
/*************线程***************/

/*************UDP线程***************/
    m_udpThread = new UdpThread;
    connect(m_udpThread, SIGNAL(sigRecvOk(QByteArray)), this, SLOT(handleResults(QByteArray)));
    connect(m_udpThread, SIGNAL(Ip_send(QString)), this, SLOT(Ip_show(QString)));
    m_udpThread->start();
    WIFI_flag=false;
/*************UDP线程***************/


      logo= new Logoshow(this);
      logo->setAttribute(Qt::WA_DeleteOnClose);
      ui->tabWidget->addTab(logo,"");
      ui->tabWidget->tabBar()->hide();
      ui->tabWidget->setVisible(true);


      QLabel *aixLabel = new QLabel("作者：左家垅的牛");
      aixLabel->setAlignment(Qt::AlignHCenter);
      statusBar()->addWidget(aixLabel, 1);


}

void MainWindow::paintEvent(QPaintEvent *event)
{

}

MainWindow::~MainWindow()
{
    // 退出串口1子线程
    chithread.quit();
    chithread.wait();
    qDebug()<<"mainend";
    delete ui;
}

void MainWindow::on_btn_seacher_clicked()
{
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())//读取串口信息
    {
        myserial->setPort(info);                        //这里相当于自动识别串口号之后添加到了cmb，如果要手动选择可以用下面列表的方式添加进去
        if(myserial->open(QIODevice::ReadWrite))
         {
          ui->com_choose->addItem(myserial->portName());//将串口号添加到cmb
          myserial->close();                            //关闭串口等待人为(打开串口按钮)打开
         }
     }


}

void MainWindow::on_btn_open_clicked()
{
    if(ui->btn_open->text()=="打开串口"){

        myserial->setPortName(ui->com_choose->currentText());
        myserial->setBaudRate(ui->box_baud->currentText().toInt()); //设置波特
        myserial->setDataBits(QSerialPort::Data8);      //设置数据位数
        myserial->setParity(QSerialPort::NoParity);     //设置奇偶校验
        myserial->setStopBits(QSerialPort::OneStop);    //设置停止位
        myserial->setFlowControl(QSerialPort::NoFlowControl);//非流控制
        if(myserial->open(QIODevice::ReadWrite)){
            qDebug()<<(ui->com_choose->currentText())<<"串口打开成功";

         SIREAL_flag=true;

        }
        ui->btn_open->setText("关闭串口");
        ui->btn_seacher->setDisabled(true);
        ui->com_choose->setDisabled(true);
    }
    else if(ui->btn_open->text()=="关闭串口"){

        myserial->close();
        qDebug()<<(ui->com_choose->currentText())<<"串口已经关闭";
        ui->btn_seacher->setDisabled(false);
        ui->com_choose->setDisabled(false);
        ui->btn_open->setText("打开串口");
        SIREAL_flag=false;

    }

}



void MainWindow::on_btn_sendstart_clicked()
{
//    timer->start(10);                     //定时器中断1s一次
    //获取界面上的数据并转换成utf8格式的字节流
    QByteArray data;
    data="1";
    emit serialDataSend(data);
    qDebug() <<  "主线程发送信号，线程ID：" << QThread::currentThreadId();



}

void MainWindow::on_btn_sendstop_clicked()
{
    if(timer->isActive())
    {
        timer->stop();
    }

}


bool INSTRCT_flag=false;
//图像接收
void MainWindow::handleResults(QByteArray result)
{
    QByteArray array;
    QByteArray tempbyte = result;
    //qDebug()<<tempbyte;
    if(SIREAL_flag==true||WIFI_flag==true)
    {
    emit sendResultToWave(tempbyte);
    emit sendDatatoImage(tempbyte);
    }

    if(INSTRCT_flag==true){
        emit sendDatatoInstruct(tempbyte);
        //qDebug()<<"0000000000"<<tempbyte;
    }


}

void MainWindow::setStatusBar(int x,int y)
{
    int pixle = 0;
    if(g_pic!=NULL)
        pixle = *(g_pic+80*y+x);
    QString strShow1 = QString("Pixle Positon: X:%1 Y:%2 Pixle value:%3").arg(x).arg(y).arg(pixle);
    ui->statusBar->showMessage(strShow1);//将光标坐标显示到状态栏
}


void MainWindow::on_actionwave_triggered()
{
     WaveForm *waveform = new WaveForm();
     waveform->show();
     waveform->setAttribute(Qt::WA_DeleteOnClose);//关闭的时候调用析构函数
     connect(this,&sendResultToWave,waveform,&WaveForm::AnalyzeData);

}


void MainWindow::on_actionimage_triggered()
{
    delete logo;
    imageshow *imag = new imageshow(this);
    imag->setAttribute(Qt::WA_DeleteOnClose);
    ui->tabWidget->addTab(imag,"");
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setVisible(true);
    connect(this,&sendDatatoImage,imag,&imageshow::DataToImage);
    connect(imag,&imageshow::sendPosToGui,this,&MainWindow::setStatusBar);//信号与槽绑定  鼠标获取坐标事件


}

void MainWindow::on_actioninstruct_triggered()
{
    INSTRCT_flag=true;
    Instruct *instruct = new Instruct();
    instruct->show();
    instruct->setAttribute(Qt::WA_DeleteOnClose);//关闭的时候调用析构函数
    connect(instruct,&Instruct::Send_instruction,this,&MainWindow::Instruct_To_Serial);
    connect(this,&MainWindow::sendDatatoInstruct,instruct,&Instruct::Receive_data);
}

void MainWindow::Instruct_To_Serial(QByteArray data){

     emit serialDataSend(data);
    // chithread.msleep(5000);

}


void MainWindow::on_actionhelp_triggered()
{
    Help *help = new Help();
    help->show();
    help->setAttribute(Qt::WA_DeleteOnClose);//关闭的时候调用析构函数
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked==true)
    {
        WIFI_flag=true;

    }
    else
        WIFI_flag=false;
}

void MainWindow::Ip_show(QString address)
{
    qDebug()<<address;
    address.append("以192开头IP为准");
    QMessageBox::information(this, "本地IP", address,1);
}

