#include "serialworker.h"
#include <QDebug>
#include <QThread>
SerialWorker::SerialWorker(QSerialPort *ser,QObject *parent)
    : QObject(parent),serial(ser)
{

}


void SerialWorker::doDataSendWork(const QByteArray data)
{
    qDebug() <<  "子线程槽函数发送数据：" << data << "线程ID：" << QThread::currentThreadId();

    // 发送数据
    serial->write(data);
}

void SerialWorker::doDataReciveWork()
{
    // 1.收到数据


    QByteArray ByteArray = serial->readAll();


//    qDebug() <<  "子线程发送结果信号：" << ByteArray << "线程ID：" << QThread::currentThreadId();

    // 3.将结果发送到主线程
    emit sendResultToGui(ByteArray);




}
