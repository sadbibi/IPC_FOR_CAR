#include "udpthread.h"
#include <QtNetwork>
#include <QMessageBox>
UdpThread::UdpThread(QObject *parent) :
    QThread(parent)
{
    m_buf = new char[1024*1024];
    memset(m_buf, 0, 6000);
    emit_flag=0;

}

UdpThread::~UdpThread()
{
    m_udpSocket->close();
    delete m_buf;

//     if(nullptr != _pTimer){
//         _pTimer->stop();
//       delete _pTimer;
//     }
    this->quit();
    this->wait();
}

void UdpThread::run()
{
    QString IP;
    m_udpSocket = new QUdpSocket;
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(slotRecv()),Qt::DirectConnection);
    qDebug()<< m_udpSocket->bind(QHostAddress::Any, 2333);//可以改成IPV4
    //qDebug()<< m_udpSocket->bind(QHostAddress("192.168.137.1"), 2333);
    QString localHostName = QHostInfo::localHostName();
    //qDebug() <<"localHostName: "<<localHostName;
    QHostInfo info = QHostInfo::fromName(localHostName);
    //qDebug() <<"IP Address: "<<info.addresses();
    foreach(QHostAddress address,info.addresses())

    {

         if(address.protocol() == QAbstractSocket::IPv4Protocol)
                {
             IP.append(address.toString());
             IP.append("\n");

         }
             //qDebug() << address.toString();

             //QMessageBox::information(&, "警告", address.toString());

    }
     emit Ip_send(IP);
    _pTimer = new QTimer;
    connect(_pTimer,&QTimer::timeout,this,UdpThread::flagset);
    _pTimer->start(1);
    exec();
}

void UdpThread::slotRecv()
{

    qDebug("\nstart");
    QByteArray tempdata;
    QByteArray data;
    if(m_udpSocket->hasPendingDatagrams()) {


        int size = m_udpSocket->pendingDatagramSize();//获取数据包大小
        tempdata.resize(size);
        m_udpSocket->readDatagram(tempdata.data(),tempdata.size());
        qDebug()<<"udp size"<<size;
        data.append(tempdata);

    }
    qDebug()<<data;
    emit sigRecvOk(data);


    data.clear();
    qDebug()<<"receTIME"<<emit_flag;
    emit_flag=0;
}

void UdpThread::flagset()
{
    emit_flag++;
}
