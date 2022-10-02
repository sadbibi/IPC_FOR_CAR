#ifndef UDPTHREAD_H
#define UDPTHREAD_H

#include <QThread>
#include "qudpsocket.h"
#include "QTimer"
struct ImageFrameHead {
    int funCode;                        //!功能码
    unsigned int uTransFrameHdrSize;	//!sizeof(WIFI_FRAME_HEADER)
    unsigned int uTransFrameSize;		//!sizeof(WIFI_FRAME_HEADER) + Data Size

    //数据帧变量
    unsigned int uDataFrameSize;		//数据帧的总大小
    unsigned int uDataFrameTotal;		//一帧数据被分成传输帧的个数
    unsigned int uDataFrameCurr;		//数据帧当前的帧号
    unsigned int uDataInFrameOffset;   	//数据帧在整帧的偏移
};

class UdpThread : public QThread
{
    Q_OBJECT
public:
    explicit UdpThread(QObject *parent = 0);
    ~UdpThread();

protected:
    virtual void run();

signals:
    void sigRecvOk(QByteArray data);
    void Ip_send(QString address);

public slots:
    void slotRecv();
    void flagset();
private:
    QUdpSocket *m_udpSocket;
    char *m_buf;
    QTimer* _pTimer;
    int emit_flag;
};

#endif // UDPTHREAD_H
