#include "imageshow.h"
#include "ui_imageshow.h"


imageshow::imageshow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::imageshow)
{
    ui->setupUi(this);
    Imagsave_flag=0;
    ui->imaglabel->setScaledContents(true);
    ui->imaglabel->setMouseTracking(true);
    connect(ui->imaglabel,&MouseEvent::getPosition,this,&imageshow::getPixPos);//信号与槽绑定  鼠标获取坐标事件

    videotimer = new QTimer();//启动定时器
    connect(videotimer,SIGNAL(timeout()),this,SLOT(VideoShow()));//连接
    //计时
    imagetimer = new QTimer();
    connect(imagetimer,SIGNAL(timeout()),this,SLOT(time_count()));//计算帧数周期
    imagetimer->start(1);
    image_interv_T=0;


    runPath = QCoreApplication::applicationDirPath();       //获取exe路径
    hglpName = "photo";                                     //和exe通路径
    hglpPath = QString("%1/%2").arg(runPath).arg(hglpName);

    Pic_num=0;
    action_flag=0;
    Image_process_flag=0;
    Pic_01_check=0;


    ui->PicSlider->setMaximum(500);


    red=QColor(255,0,0);
    blue=QColor(0,0,255);
    yellow=QColor(255,255,0);
    green=QColor(0,255,0);
}

void imageshow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);



}
imageshow::~imageshow()
{
    delete ui;
    delete videotimer;//定时器
    delete imagetimer;//定时器
}


imageshow::color_border(uchar *oripic,QImage *latpic)
{
    for(int i=0;i<ui->spinBox_height->value();i++)
    {
        for(int j=0;j<ui->spinBox_width->value();j++)
        {
            if(oripic[i*ui->spinBox_width->value()+j]==RED)
                latpic->setPixelColor(j,i,red);
            if(oripic[i*ui->spinBox_width->value()+j]==BLUE)
                latpic->setPixelColor(j,i,blue);
            if(oripic[i*ui->spinBox_width->value()+j]==YELLOW)
                latpic->setPixelColor(j,i,yellow);
            if(oripic[i*ui->spinBox_width->value()+j]==GREEN)
                latpic->setPixelColor(j,i,green);
        }
    }
}


//QByteArray g_array;
uchar *g_pic = NULL;
imageshow::DataToImage(QByteArray data)
{

   ui->line_bufsize->setText(QString("%1").arg(data.size()));
    //qDebug()<<data;

    static int num=1;

    QByteArray array;
    byteArray.append(data);
  qDebug()<<"SIZE"<<byteArray.size();


    if(byteArray.contains("CSU")||byteArray.contains("USC")){

        if(byteArray.contains("CSU")&&!byteArray.contains("USC"))//只有开始标志
        {
            byteArray = byteArray.right(byteArray.length()-byteArray.indexOf("CSU")-3);

        }
        if(byteArray.contains("USC")&&!byteArray.contains("CSU"))//只有结束标志
        {
            array = byteArray.left(byteArray.indexOf("USC"));
            byteArray=byteArray.left(0);
        }

        if(byteArray.contains("USC")&&byteArray.contains("CSU"))//开始结束都存在
        {
             array = byteArray.left(byteArray.indexOf("USC"));
             byteArray=byteArray.right(byteArray.length()-byteArray.lastIndexOf("CSU")-3);
        }

    }


//        if(data.contains("USC")&&data.contains("CSU")){
//            array=byteArray.mid(byteArray.indexOf("USC"),byteArray.length()-byteArray.lastIndexOf("USC")-3);
//            qDebug()<<array.size();

//        }
    //qDebug()<<byteArray.size();
    qDebug()<<"picTIME"<<image_interv_T;
    ui->line_picT->setText(QString("%1").arg(image_interv_T));
    image_interv_T=0;

    if(array.size()==ui->spinBox_width->value()*ui->spinBox_height->value())//图像大小正常表示图像接受没问题
    {
//        g_array = array;
        uchar * transData = (unsigned char*)array.data();

        if(Image_process_flag)
            transData = imagepro.Imageprocess(transData);
        g_pic = transData;
        QImage img(transData,ui->spinBox_width->value(),ui->spinBox_height->value(),ui->spinBox_width->value(),QImage::Format_Indexed8);//8位灰度
        QPixmap Pixmap0 = QPixmap::fromImage(img);
        /********把PIXMAP转化成IMAGE用于边界有色处理********/
                QImage tempImage = Pixmap0.toImage();

              if(Image_process_flag||Pic_01_check)//图像处理或者传二值边界图需要下面这段代码
                   color_border(transData,&tempImage);
//                for(int i=0;i<ui->spinBox_height->value();i++)
//                {
//                    for(int j=0;j<ui->spinBox_width->value();j++)
//                    {
//                        if(transData[i*ui->spinBox_width->value()+j]==RED)
//                            tempImage.setPixelColor(j,i,red);
//                        if(transData[i*ui->spinBox_width->value()+j]==BLUE)
//                            tempImage.setPixelColor(j,i,blue);


//                    }
//                }

              QPixmap Pixmap1 = QPixmap::fromImage(tempImage);
        /********把PIXMAP转化成IMAGE用于边界有色处理********/
        ui->imaglabel->setAlignment(Qt::AlignCenter);		//居中显示
        ui->imaglabel->setPixmap(Pixmap1);
        ui->imaglabel->resize(ui->scrollArea->size());

        if(Imagsave_flag){
            img.save(QString("%1/Pic%2.png").arg(hglpPath).arg(num));
            num++;
        }
    }
}

imageshow::getPixPos(QPointF pt)
{


    int width,height,pixle_X,pixle_Y;
    width = ui->imaglabel->contentsRect().width();
    height = ui->imaglabel->contentsRect().height();
    pixle_X = (int)((pt.x()*ui->spinBox_width->value()/width));
    pixle_Y = (int)((pt.y()*ui->spinBox_height->value()/height));
    QString strShow1 = QString("size coord: X:%1 Y:%2").arg(pixle_X).arg(pixle_Y);
    emit sendPosToGui(pixle_X,pixle_Y);
//    qDebug()<<strShow1;


}

void imageshow::on_btn_imagesave_clicked()
{

    if(ui->btn_imagesave->text()=="保存图片")
    {

        qDebug()<<"save";
        Imagsave_flag=1;
        ui->btn_imagesave->setText("取消保存");
    }

    else if(ui->btn_imagesave->text()=="取消保存")
    {
        ui->btn_imagesave->setText("保存图片");
        Imagsave_flag=0;
    }





}

void imageshow::on_btn_imageread_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.png *.jpeg *.bmp)"));

    if (fileName.isEmpty())
    {
           QMessageBox::information(this, "警告", "没有选择文件");
           return;
    }

    QImage img;
    img.load(fileName);//加载文件




    if(img.size().height()*img.size().width()==ui->spinBox_width->value()*ui->spinBox_height->value())//图像大小正常表示图像接受没问题
    {


/***********先把image转换为tans之后进行图像处理在转化成PIXMAP显示*****************/
        uchar *trans = new uchar[ui->spinBox_width->value()*ui->spinBox_height->value()];

        for(int i=0;i<ui->spinBox_height->value();i++)
        { for(int j=0;j<ui->spinBox_width->value();j++)
            {

                    QRgb color = img.pixel(j, i);
                    int gray = qGray(color);
                    trans[i*ui->spinBox_width->value()+j]=gray;
            }
        }
        if(Image_process_flag)
            trans= imagepro.Imageprocess(trans);
        g_pic = trans;
        QImage imge(trans,ui->spinBox_width->value(),ui->spinBox_height->value(),ui->spinBox_width->value(),QImage::Format_Indexed8);//8位灰度
        QPixmap Pixmap0 = QPixmap::fromImage(imge);
/***********先把image转换为tans之后进行图像处理在转化成PIXMAP显示*****************/



/********把PIXMAP转化成IMAGE用于边界有色处理********/
        QImage tempImage = Pixmap0.toImage();

      if(Image_process_flag||Pic_01_check)
          color_border(trans,&tempImage);
//        for(int i=0;i<ui->spinBox_height->value();i++)
//        {
//            for(int j=0;j<ui->spinBox_width->value();j++)
//            {
//                if(trans[i*ui->spinBox_width->value()+j]==RED)
//                    tempImage.setPixelColor(j,i,red);
//                if(trans[i*ui->spinBox_width->value()+j]==BLUE)
//                    tempImage.setPixelColor(j,i,blue);


//            }
//        }
      QPixmap Pixmap1 = QPixmap::fromImage(tempImage);
/********把PIXMAP转化成IMAGE用于边界有色处理********/



        ui->imaglabel->setAlignment(Qt::AlignCenter);		//居中显示
        ui->imaglabel->setPixmap(Pixmap1);
        ui->imaglabel->resize(ui->scrollArea->size());
    }





}

void imageshow::on_btn_videosave_clicked() //png图集转mp4
{

        QString folder_path = QFileDialog::getExistingDirectory(this,"选择文件目录","",QFileDialog::ShowDirsOnly
                                                                | QFileDialog::DontResolveSymlinks);
        if(folder_path.isEmpty())   return;

        QString outFilename = QFileDialog::getSaveFileName(this,"选择保存路径",folder_path+"/视频文件","*.avi;;*.mp4 ");
        if(outFilename.isEmpty())   return;


        AVFormatContext *kAVFormatContext;
        AVOutputFormat *kAVOutputFormat= new AVOutputFormat();
        AVCodecContext *kAVCodecContext;
        AVDictionary *kAVDictionary = NULL;
        AVDictionary *opt = NULL;
        AVCodec *video_codec;
        AVStream *kAVStream;
        AVFrame *frame;
        AVFrame *tmp_frame;
        AVPacket kAVPacket = { 0 };
        struct SwsContext *kSwsContext;
        AVRational time{1,20};  /*1s25帧*/
        AVRational time_1{1,1};  /*1s25帧*/
        uint8_t *intBuffer = 0;                           // 图片数据缓冲区
        int i=0;
        bool a=false;
        int ret;
        int got_packer = 0;
        int64_t next_pts = 0;

        tmp_frame = av_frame_alloc();
        av_init_packet(&kAVPacket);

        av_register_all();     //1、注册所有容易和编解码器

        /* 2、分配输出媒体上下文 */
        avformat_alloc_output_context2(&kAVFormatContext, NULL, NULL, outFilename.toLocal8Bit().data());      //上下文结构体、输出结构体、文件类型、路径

        if(!kAVFormatContext)        //如果根据文件名没有找到对应的格式则默认mpeg格式
        {

            ret = avformat_alloc_output_context2(&kAVFormatContext, NULL, "mpeg",  outFilename.toLocal8Bit().data());    //没有找到文件类型默认mpeg（MP4）

        }
        if(!kAVOutputFormat) { qDebug()<<"err";goto end;}

        kAVOutputFormat = kAVFormatContext->oformat;    //把输出操作结构体赋值出来

        if (!(kAVOutputFormat->flags & AVFMT_NOFILE))   /* 如果需要，打开输出文件*/
        {
            ret = avio_open(&kAVFormatContext->pb, outFilename.toLocal8Bit().data(), AVIO_FLAG_WRITE);  //3、打开输出文件
            if (ret < 0) {qDebug()<<"打开输出文件失败。"<<ret; }
        }

        /* 使用默认格式的编解码器添加音频和视频流，并初始化编解码器。*/
        if (kAVOutputFormat->video_codec != AV_CODEC_ID_NONE)
        {
            video_codec = avcodec_find_encoder(kAVOutputFormat->video_codec);   //4、找到编码器
            if(!video_codec)    goto end;

            kAVStream = avformat_new_stream(kAVFormatContext,NULL);         //5、新建一个输出流
            if(!kAVStream) {qDebug()<<"创建流kAVStream失败。";goto end;}

            kAVCodecContext = avcodec_alloc_context3(video_codec);      //初始化一个AVCodecContext
            if(!kAVCodecContext)    {qDebug()<<"用编码器video_codec初始化的kAVCodecContext默认参数失败";goto end;}

            switch(video_codec->type)
            {
            case AVMEDIA_TYPE_VIDEO:

                kAVCodecContext->codec_id = video_codec->id;
                kAVCodecContext->bit_rate = 800000;
                kAVCodecContext->width = ui->spinBox_width->value();
                kAVCodecContext->height = ui->spinBox_height->value();
                kAVStream->time_base = time;
                kAVCodecContext->time_base = time;
                kAVCodecContext->gop_size = 12; /*最多每十二帧发射一个内帧 */
                kAVCodecContext->pix_fmt = AV_PIX_FMT_YUV420P;
                if (kAVCodecContext->codec_id == AV_CODEC_ID_MPEG2VIDEO)
                {
                    kAVCodecContext->max_b_frames = 2;  /*为了测试，我们还添加了b帧*/
                }
                if (kAVCodecContext->codec_id == AV_CODEC_ID_MPEG1VIDEO)
                {
                    /* 需要避免使用一些coeffs溢出的宏块。这在正常的视频中不会发生，
                     * 只是在色度平面的运动与luma平面不匹配时才会发生。 */
                    kAVCodecContext->mb_decision = 2;
                }

                break;
            case AVMEDIA_TYPE_AUDIO:
                break;

            default:
                break;
            }

            if(kAVOutputFormat->flags & AVFMT_GLOBALHEADER)/*有些格式希望流标头是单独的*/
            {
                kAVCodecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
            }
        }

        av_dict_copy(&opt,kAVDictionary, 0);
        ret = avcodec_open2(kAVCodecContext,video_codec,&opt);      //6、打开编码器
        if(ret<0){qDebug()<<"打开视频编解码器失败"<<ret; goto end;}
        av_dict_free(&opt);

        frame = av_frame_alloc();
        if(!frame)  {qDebug()<<"分配帧失败."; goto end;}
        frame->format = kAVCodecContext->pix_fmt;
        frame->width = kAVCodecContext->width;
        frame->height = kAVCodecContext->height;

        ret = av_frame_get_buffer(frame, 32);   //分配内存空间frame必须要有上三条件，32也就是4字节对齐
        if(ret < 0){qDebug()<<"frame分配内存失败"; goto end;}

        ret = avcodec_parameters_from_context(kAVStream->codecpar,kAVCodecContext);/*将流参数复制到muxer */
        if (ret < 0) {qDebug()<<"无法复制流参数";goto end; }

        av_dump_format(kAVFormatContext, 0, outFilename.toLocal8Bit().data(), 1);     //打印输出文件的详细信息


        ret = avformat_write_header(kAVFormatContext,&kAVDictionary);/* 7、写流标头(如果有的话)*/
        if(ret < 0){qDebug()<<"写流标题失败"; goto end;}



        while(!a)
        {


            if (av_frame_make_writable(frame) < 0)  {goto end;}  /*当我们传递一个帧给编码器时，它可能会在内部保留一个对它的引用;确保我们没有在这里覆盖它*/

            QImage img(tr("%1/Pic%2.png").arg(folder_path).arg(i+1));
            QImage image(tr("%1/Pic%2.png").arg(folder_path).arg(i+2));
            a=image.isNull();
            i++;
            if(img.isNull()){qDebug()<<"打开图片失败";break;}
            img = img.convertToFormat(QImage::Format_RGB888);

            kSwsContext = sws_getContext(kAVCodecContext->width,kAVCodecContext->height,
                                         AV_PIX_FMT_RGB24,kAVCodecContext->width,kAVCodecContext->height,
                                         AV_PIX_FMT_YUV420P,SWS_LANCZOS | SWS_ACCURATE_RND,NULL,NULL,NULL);
            if(!kSwsContext){qDebug()<<"无法初始化图片转换器";    goto end;}


            intBuffer = (uint8_t*)malloc(sizeof(uint8_t)*img.bytesPerLine()*img.height());
            memcpy(intBuffer,img.constBits(),sizeof(uint8_t)*img.bytesPerLine()*img.height());
            avpicture_fill((AVPicture *)tmp_frame,intBuffer,AV_PIX_FMT_RGB24,kAVCodecContext->width,kAVCodecContext->height); //pAVFrame32的data指针指向了outBuffer

            sws_scale(kSwsContext,(const uint8_t * const *)tmp_frame->data,
                      tmp_frame->linesize,0,kAVCodecContext->height,frame->data,frame->linesize);   //图片信息转换
            sws_freeContext(kSwsContext);
            kSwsContext = 0;

            frame->pts = next_pts++;
            //frame->pts = i*(kAVStream->time_base.den)/((kAVStream->time_base.num)*24);

            got_packer = 0;
            ret = avcodec_encode_video2(kAVCodecContext,&kAVPacket,frame,&got_packer);  //8、编码、把一帧数据编码成AVPacket
            if(ret < 0) {qDebug()<<"错误编码视频帧"<<ret; goto end;}

            if(got_packer)
            {
                av_packet_rescale_ts(&kAVPacket, kAVCodecContext->time_base, kAVStream->time_base);
                kAVPacket.stream_index = kAVStream->index;
                ret = av_write_frame(kAVFormatContext, &kAVPacket); /*将压缩帧写入媒体文件。 */
                av_free_packet(&kAVPacket);
            }else
            {ret = 0;}
            free(intBuffer);intBuffer = 0;
            if(ret<0){ qDebug()<<"写入video文件失败"<<ret<<kAVPacket.stream_index; break; }
        }
        qDebug()<<i;

        /*  选择写预告片，如果有的话。预告片必须在你之前写好 当你写标题时关闭CodecContexts打开;否则
            av_write_trailer()可以尝试使用被释放的内存  av_codec_close()。要编码的流 */
        av_write_trailer(kAVFormatContext);

    end:
        /* 关闭每个编解码器。 */
        avcodec_free_context(&kAVCodecContext);
        av_frame_free(&frame);

        if (!(kAVOutputFormat->flags & AVFMT_NOFILE))
            avio_closep(&kAVFormatContext->pb);/*关闭输出文件*/

        qDebug()<<"mp4end";
        avformat_free_context(kAVFormatContext);   /*释放上下文*/


}


//视频转化成图片集
int imageshow::videoToImage(const QString &audioPath, const QString &outputDir)
{

    AVFormatContext* formatContext=avformat_alloc_context();                                    //分配fomat上下文

    if(avformat_open_input(&formatContext,audioPath.toLocal8Bit().data(),nullptr,nullptr)!=0){  //打开输入流
        qDebug()<<"can`t open the file.";
        return -1;
    }

    av_dump_format(formatContext,0,audioPath.toLocal8Bit(),0);                                  //在终端打印

    if(avformat_find_stream_info(formatContext, nullptr)!=0){                                   //加载输入流中的信息
        qDebug()<<"can`t find stream infomation";
        return -1;
    }

    int videoStreamIndex=-1;
    for(uint i=0;i<formatContext->nb_streams;i++){
        if(formatContext->streams[i]->codecpar->codec_type==AVMEDIA_TYPE_VIDEO){                //查找第一个视频流（一个视频中可能有多个流（音频+视频））
            videoStreamIndex=i;
            break;
        }
    }

    if(videoStreamIndex==-1){
        qDebug()<<"didn`t find a video stream";
        return -1;
    }

    AVCodecParameters *codecParam=formatContext->streams[videoStreamIndex]->codecpar;           //获取编解码器的参数集
    AVCodec* codec=avcodec_find_decoder(codecParam->codec_id);                                  //获取编解码器
    AVCodecContext* codecContext=avcodec_alloc_context3(nullptr);                               //获取编解码上下文
    avcodec_parameters_to_context(codecContext,codecParam);                                     //根据编解码器参数填充编解码上下文

    if(codec==nullptr){
        qDebug()<<"can`t find codec.";
        return -1;
    }
    if( avcodec_open2(codecContext,codec,nullptr)!=0){                                          //开启编解码器
        qDebug()<<"can`t open codec";
        return -1;
    }

    AVPacket *packet = av_packet_alloc();                                                       //分配一个数据包

    AVFrame* frame=av_frame_alloc();                                                            //分配一个视频帧

    QImage output(codecParam->width,codecParam->height,QImage::Format_RGB888);                  //构造一个QImage用作输出
    int outputLineSize[3];                                                                         //构造AVFrame到QImage所需要的数据
    av_image_fill_linesizes(outputLineSize,AV_PIX_FMT_RGB24,codecParam->width);
    uint8_t *outputDst[]={output.bits()};

    //构造一个格式转换上下文
    SwsContext *imgConvertContext=sws_getContext(codecParam->width,codecParam->height,(AVPixelFormat)codecParam->format,codecParam->width,codecParam->height,AV_PIX_FMT_BGR24,SWS_BICUBIC,NULL,NULL,NULL);

    int index = 1;
    while (true) {
        if(av_read_frame(formatContext,packet)<0)
            break;
        if(packet->stream_index==videoStreamIndex){
            if(avcodec_send_packet(codecContext,packet)!=0)
                continue;
            if(avcodec_receive_frame(codecContext,frame)!=0)
                continue;
            sws_scale(imgConvertContext,frame->data,frame->linesize,0,codecParam->height,outputDst,outputLineSize);
            output.save(outputDir + QString::number(index++)+".png");
        }
    }
    Pic_num=--index;
    qDebug()<<Pic_num;
    av_frame_free(&frame);
    av_packet_free(&packet);
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);
}




QString videoshowfilename;
void imageshow::on_btn_videoread_clicked()
{

    QString videofileName = QFileDialog::getOpenFileName(this, tr("选择视频文件"), ".", tr("Image Files(*.avi)"));

    if(videofileName.isEmpty())   return;

    QString outFilename = QFileDialog::getSaveFileName(this,"选择保存路径",videofileName+"/Pic","*png ");

    if(outFilename.isEmpty())   return;

    videoToImage(videofileName,outFilename);

    videoshowfilename=outFilename;

}


void imageshow::on_btn_videoshow_clicked()
{
    videotimer->start(35);
    action_flag=1;

}


static int  n = 1;
void imageshow::VideoShow()
{


    QString dir= videoshowfilename + QString::number(n++)+".png";
    QImage img;
    img.load(dir);//加载文件
    if(img.size().height()*img.size().width()==ui->spinBox_width->value()*ui->spinBox_height->value())//图像大小正常表示图像接受没问题
    {
//         QPixmap Pixmap = QPixmap::fromImage(img);
        uchar *trans = new uchar[ui->spinBox_width->value()*ui->spinBox_height->value()];

        for(int i=0;i<ui->spinBox_height->value();i++)
        { for(int j=0;j<ui->spinBox_width->value();j++)
            {

                    QRgb color = img.pixel(j, i);
                    int gray = qGray(color);
                    trans[i*ui->spinBox_width->value()+j]=gray;
            }
        }
        if(Image_process_flag)
            trans= imagepro.Imageprocess(trans);
        g_pic = trans;
        QImage imge(trans,ui->spinBox_width->value(),ui->spinBox_height->value(),ui->spinBox_width->value(),QImage::Format_Indexed8);//8位灰度
        QPixmap Pixmap0 = QPixmap::fromImage(imge);
        /********把PIXMAP转化成IMAGE用于边界有色处理********/
                QImage tempImage = Pixmap0.toImage();
              if(Image_process_flag||Pic_01_check)
                  color_border(trans,&tempImage);
//                for(int i=0;i<ui->spinBox_height->value();i++)
//                {
//                    for(int j=0;j<ui->spinBox_width->value();j++)
//                    {
//                        if(trans[i*ui->spinBox_width->value()+j]==RED)
//                            tempImage.setPixelColor(j,i,red);
//                        if(trans[i*ui->spinBox_width->value()+j]==BLUE)
//                            tempImage.setPixelColor(j,i,blue);


//                    }
//                }
              QPixmap Pixmap1 = QPixmap::fromImage(tempImage);
        /********把PIXMAP转化成IMAGE用于边界有色处理********/

        ui->imaglabel->setAlignment(Qt::AlignCenter);		//居中显示
        ui->imaglabel->setPixmap(Pixmap1);
        ui->imaglabel->resize(ui->scrollArea->size());
        ui->Piclabel->setText(QString::number(n-1));
        ui->PicSlider->setValue((n-1)*500/Pic_num);
    }


   if(img.isNull()) {
       videotimer->stop();
       n=1;
       action_flag=0;
   }
}



void imageshow::on_PicSlider_valueChanged(int value)
{
//    QString Pic_num_now=QString::number(value*Pic_num/100+1);
//    n=value*Pic_num/100+1;
//    ui->Piclabel->setText(Pic_num_now);
}

void imageshow::on_PicSlider_sliderPressed()
{


}

void imageshow::on_PicSlider_actionTriggered(int action)
{
    if(action_flag==1)
    {
        QString Pic_num_now=QString::number(ui->PicSlider->value()*Pic_num/500+1);
        n=ui->PicSlider->value()*Pic_num/500+1;
        ui->Piclabel->setText(Pic_num_now);
   }
    else if(action_flag==0){
        QString dir= videoshowfilename + QString::number(ui->PicSlider->value()*Pic_num/500+1)+".png";

        QString Pic_num_now=QString::number(ui->PicSlider->value()*Pic_num/500+1);
        ui->Piclabel->setText(Pic_num_now);

        QImage img;
        img.load(dir);//加载文件
//        QPixmap Pixmap = QPixmap::fromImage(img);
        uchar *trans = new uchar[ui->spinBox_width->value()*ui->spinBox_height->value()];

        for(int i=0;i<ui->spinBox_height->value();i++)
        { for(int j=0;j<ui->spinBox_width->value();j++)
            {

                    QRgb color = img.pixel(j, i);
                    int gray = qGray(color);
                    trans[i*ui->spinBox_width->value()+j]=gray;
            }
        }
        if(Image_process_flag)
            trans= imagepro.Imageprocess(trans);
        g_pic = trans;
        QImage imge(trans,ui->spinBox_width->value(),ui->spinBox_height->value(),ui->spinBox_width->value(),QImage::Format_Indexed8);//8位灰度
        QPixmap Pixmap0 = QPixmap::fromImage(imge);

        /********把PIXMAP转化成IMAGE用于边界有色处理********/
                QImage tempImage = Pixmap0.toImage();
              if(Image_process_flag||Pic_01_check)
                  color_border(trans,&tempImage);
//                for(int i=0;i<ui->spinBox_height->value();i++)
//                {
//                    for(int j=0;j<ui->spinBox_width->value();j++)
//                    {
//                        if(trans[i*ui->spinBox_width->value()+j]==RED)
//                            tempImage.setPixelColor(j,i,red);
//                        if(trans[i*ui->spinBox_width->value()+j]==BLUE)
//                            tempImage.setPixelColor(j,i,blue);


//                    }
//                }
              QPixmap Pixmap1 = QPixmap::fromImage(tempImage);
        /********把PIXMAP转化成IMAGE用于边界有色处理********/

        ui->imaglabel->setAlignment(Qt::AlignCenter);		//居中显示
        ui->imaglabel->setPixmap(Pixmap1);
        ui->imaglabel->resize(ui->scrollArea->size());

    }
}

void imageshow::on_PicSlider_sliderMoved(int position)
{

}

void imageshow::on_checkBox_clicked(bool checked)
{
    if(checked)
        Image_process_flag=1;
    else
        Image_process_flag=0;
}

void imageshow::time_count()
{
   image_interv_T++;
}


void imageshow::on_Pic_01_check_clicked(bool checked)
{
    if(checked){
        Pic_01_check=1;
    }
    else {
        Pic_01_check=0;
    }
}

void imageshow::on_btn_atlas_clicked()
{

    QString outFilename = QFileDialog::getSaveFileName(this,"选择保存路径",hglpPath+"/Pic");
    QString outFilename1 = outFilename.left(outFilename.indexOf("/Pic"));
    if(outFilename.isEmpty())   return;


    QDir dir(outFilename1);
        dir.setFilter(QDir::Files);
    //加过滤器，选择前缀为name的文件
        QStringList filters;
        filters << "Pic*";
        dir.setNameFilters(filters);
        QFileInfoList list=dir.entryInfoList();
        QFileInfo fileInfo;
        QStringList filelist;
        foreach (fileInfo, list)
        {
            filelist << fileInfo.fileName();
        }
        Pic_num = filelist.count();
        qDebug()<<Pic_num;
        videoshowfilename=outFilename;
}
