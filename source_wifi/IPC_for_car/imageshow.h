#ifndef IMAGESHOW_H
#define IMAGESHOW_H
#include <QDebug>
#include <QLabel>
#include <QPoint>
#include <QWidget>
#include <QSerialPortInfo>
#include <QThread>
#include <QPointF>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>
#include <iostream>
#include <string>
#include "mainwindow.h"
#include <QPainter>
#include "imageprocess.h"

#include <qimage.h>
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/dict.h>
#include <libswscale/swscale.h>
#include "libavdevice/avdevice.h"
#include "libavformat/avio.h"
#include "libavutil/imgutils.h"

}
using namespace std;

namespace Ui {
class imageshow;
}

class imageshow : public QWidget
{
    Q_OBJECT

public:
    explicit imageshow(QWidget *parent = 0);
    ~imageshow();
    void paintEvent(QPaintEvent *event);
public slots:
    DataToImage(QByteArray data);
    getPixPos(QPointF pt);
signals:
    sendPosToGui(int x,int y);
private slots:
    void on_btn_imagesave_clicked();

    void on_btn_imageread_clicked();

    void on_btn_videosave_clicked();

    void on_btn_videoread_clicked();

    void on_btn_videoshow_clicked();

    void VideoShow();

    void on_PicSlider_valueChanged(int value);

    void on_PicSlider_sliderPressed();

    void on_PicSlider_actionTriggered(int action);

    void on_PicSlider_sliderMoved(int position);

    void on_checkBox_clicked(bool checked);

    void time_count();//计时



    void on_Pic_01_check_clicked(bool checked);

    void on_btn_atlas_clicked();

private:
    Ui::imageshow *ui;
    int Imagsave_flag;//保存图像标志位
    int videoToImage(const QString &audioPath,const QString&outputDir);//把视频转换成图像集

    QTimer *videotimer;//定时器
    QTimer *imagetimer;//定时器
    QByteArray byteArray;

    /* 图像保存路径*/
    QString runPath;
    QString hglpName;
    QString hglpPath;
    ImageProcess imagepro;

    int Pic_num;//视频转换出来的图片数量
    int action_flag;//播放标志
    int Image_process_flag;//图像处理标志位
    int Pic_01_check;//二值带边界标志位
    int image_interv_T;//图像时间间隔
    QColor red;
    QColor blue;
    QColor yellow;
    QColor green;
    std::vector<int> data0;

private:
    color_border(uchar *oripic,QImage *latpic);



};


extern  uchar *g_pic;
#endif // IMAGESHOW_H
