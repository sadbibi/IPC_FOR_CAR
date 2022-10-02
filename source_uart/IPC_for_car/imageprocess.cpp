#include "imageprocess.h"

ImageDealDatatypedef ImageDeal[60];
ImageStatustypedef ImageStatus;
static uchar* PicTemp;                         //保存单行图像
uchar Image_Use[60][80];
uchar Pixle[60][80];
static int  BottomBorderRight = 79,  // 59行右边界
            BottomBorderLeft = 0,           // 59行左边界
            BottomCenter = 0;               // 59行中点
int Ysite=0;
int Xsite=0;
uchar ExtenLFlag = 0;  //是否左延长标志
uchar ExtenRFlag = 0;  //是否右延长标志
static int IntervalLow = 0, IntervalHigh = 0;  //定义高低扫描区间
static int ytemp = 0;
static int TFSite = 0, FTSite = 0;
static float DetR = 0, DetL = 0;
int ImageScanInterval=5;
int ImageScanInterval_Cross=5;


ImageProcess::ImageProcess(QWidget *parent) : QWidget(parent)
{



}

uchar *ImageProcess::Imageprocess(uchar *origPic)
{
    uchar *a = new uchar[4800];
    imageInit(origPic);
    Get01change_dajin();
    Pixle_Filter();
    DrawLinesFirst();     //绘制底边
    DrawLinesProcess();   //得到基本边线
    DrawLine();



    for (int i=0;i<60;i++)
    {

        for(int j=0;j<80;j++)
        {

            if(j==ImageDeal[i].LeftBorder||j==ImageDeal[i].RightBorder)
                a[i*80+j]=RED;

            else if(j==ImageDeal[i].Center)
                a[i*80+j]=BLUE;
            else
                a[i*80+j] =255*Pixle[i][j];

        }






    }



    return a;
}

void ImageProcess::imageInit(uchar *Pic)
{



/******图像数组赋值***********/
        for (int i=0;i<60;i++)
        {

            for(int j=0;j<80;j++)
            {

                    Image_Use[i][j]=Pic[i*80+j];
            }
        }

/******图像数组赋值***********/



    ImageStatus.OFFLine = 0;  //这个值根据真实距离得到，必须进行限制
    ImageStatus.WhiteLine = 0;
    for (Ysite = 59; Ysite >= ImageStatus.OFFLine; Ysite--) {
      ImageDeal[Ysite].IsLeftFind = 'F';
      ImageDeal[Ysite].IsRightFind = 'F';
      ImageDeal[Ysite].LeftBorder = 0;
      ImageDeal[Ysite].RightBorder = 79;
      ImageDeal[Ysite].LeftTemp = 0;
      ImageDeal[Ysite].RightTemp = 79;
      ImageDeal[Ysite].Black_Wide_L = 39;
      ImageDeal[Ysite].Black_Wide_R = 39;
      ImageDeal[Ysite].BlackWide = 0;

      // g  5.12
      ImageDeal[Ysite].close_LeftBorder = 0;
      ImageDeal[Ysite].close_RightBorder = 0;
      ImageDeal[Ysite].opp_LeftBorder = 0;
      ImageDeal[Ysite].opp_RightBorder = 0;

    }  //边界与标志位初始化


    ImageStatus.Threshold_detach=220;
    ImageStatus.Threshold_static=70;
}

void ImageProcess::Get01change_dajin()
{
    ImageStatus.Threshold =Threshold_deal(Image_Use[0], LCDW, LCDH, ImageStatus.Threshold_detach);
    if (ImageStatus.Threshold < ImageStatus.Threshold_static)
      ImageStatus.Threshold = ImageStatus.Threshold_static;
    qDebug()<<ImageStatus.Threshold;
    int i, j = 0;
    int thre;
    for (i = 0; i < LCDH; i++) {
      for (j = 0; j < LCDW; j++) {
        if (j <= 15)
          thre = ImageStatus.Threshold - 10;
        else if ((j > 70 && j <= 75))
          thre = ImageStatus.Threshold - 10;
        else if (j >= 65)
          thre = ImageStatus.Threshold - 10;
        else
          thre = ImageStatus.Threshold;

        if (Image_Use[i][j] >ImageStatus.Threshold )  //数值越大，显示的内容越多，较浅的图像也能显示出来
          Pixle[i][j] = 1;  //白
        else
          Pixle[i][j] = 0;  //黑
      }
    }
}

int ImageProcess::Threshold_deal(uchar *image, int col, int row, int pixel_threshold)
{
#define GrayScale 256
  int width = col;
  int height = row;
  int pixelCount[GrayScale];
  float pixelPro[GrayScale];
  int i, j, pixelSum = width * height;
  int threshold = 0;
  uchar * data = image;  //指向像素数据的指针
  for (i = 0; i < GrayScale; i++) {
    pixelCount[i] = 0;
    pixelPro[i] = 0;
  }

  int gray_sum = 0;
  //统计灰度级中每个像素在整幅图像中的个数
  for (i = 0; i < height; i += 1) {
    for (j = 0; j < width; j += 1) {

      pixelCount[(
          int)data[i * width + j]]++;  //将当前的点的像素值作为计数数组的下标
      gray_sum += (int)data[i * width + j];  //灰度值总和
    }
  }

  //计算每个像素值的点在整幅图像中的比例

  for (i = 0; i < GrayScale; i++) {
    pixelPro[i] = (float)pixelCount[i] / pixelSum;
  }

  //遍历灰度级[0,255]
  float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;

  w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
  for (j = 0; j < pixel_threshold; j++) {
    w0 +=
        pixelPro[j];  //背景部分每个灰度值的像素点所占比例之和 即背景部分的比例
    u0tmp += j * pixelPro[j];  //背景部分 每个灰度值的点的比例 *灰度值

    w1 = 1 - w0;
    u1tmp = gray_sum / pixelSum - u0tmp;

    u0 = u0tmp / w0;    //背景平均灰度
    u1 = u1tmp / w1;    //前景平均灰度
    u = u0tmp + u1tmp;  //全局平均灰度
    deltaTmp = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
    if (deltaTmp > deltaMax) {
      deltaMax = deltaTmp;
      threshold = j;
    }
    if (deltaTmp < deltaMax) {
      break;
    }
  }
  return threshold;
}

void ImageProcess::Pixle_Filter()
{
    int nr;  //行
      int nc;  //列

      for (nr = 10; nr < 40; nr++) {
        for (nc = 10; nc < 70; nc = nc + 1) {
          if ((Pixle[nr][nc] == 0) && (Pixle[nr - 1][nc] + Pixle[nr + 1][nc] + Pixle[nr][nc + 1] + Pixle[nr][nc - 1] >=3)) {
            Pixle[nr][nc] = 1;
          }
        }
      }
}

void ImageProcess::GetJumpPointFromDet(uchar *p, uchar type, int L, int H, JumpPointtypedef *Q)
{
    int i = 0;
      if (type == 'L')  //扫描左边线
      {
        for (i = H; i >= L; i--) {
          if (*(p + i) == 1 && *(p + i - 1) != 1)  //由黑变白
          {
            Q->point = i;   //记录左边线
            Q->type = 'T';  //正确跳变
            break;
          } else if (i == (L + 1))  //若果扫到最后也没找到
          {
            if (*(p + (L + H) / 2) != 0)  //如果中间是白的
            {
              Q->point = (L + H) / 2;  //认为左边线是中点
              Q->type = 'W';  //非正确跳变且中间为白，认为没有边
              break;
            } else  //非正确跳变且中间为黑
            {
              Q->point = H;   //如果中间是黑的
              Q->type = 'H';  //左边线直接最大值，认为是大跳变
              break;
            }
          }
        }
      } else if (type == 'R')  //扫描右边线
      {
        for (i = L; i <= H; i++)  //从右往左扫
        {
          if (*(p + i) == 1 && *(p + i + 1) != 1)  //找由黑到白的跳变
          {
            Q->point = i;  //记录
            Q->type = 'T';
            break;
          } else if (i == (H - 1))  //若果扫到最后也没找到
          {
            if (*(p + (L + H) / 2) != 0)  //如果中间是白的
            {
              Q->point = (L + H) / 2;  //右边线是中点
              Q->type = 'W';
              break;
            } else  //如果中点是黑的
            {
              Q->point = L;  //左边线直接最大值
              Q->type = 'H';
              break;
            }
          }
        }
      }
}

void ImageProcess::GetJumpPointFromCenter(uchar *p, JumpPointtypedef *L, JumpPointtypedef *R, int Center)
{
    int n = 0;
     for (n = Center; n <= 79; n++) {
       if (*(p + n) != 0 && *(p + n + 1) == 0) {
         R->point = n;
         R->type = 'T';
         break;
       } else if (n == 78) {
         R->point = n + 1;
         R->type = 'W';
         break;
       }
     }
     for (n = Center; n >= 1; n--) {
       if (*(p + n) != 0 && *(p + n - 1) == 0) {
         L->point = n - 1;
         L->type = 'T';
         break;
       } else if (n == 1) {
         L->point = n - 1;
         L->type = 'W';
         break;
       }
     }
}

void ImageProcess::GetJumpPointFromOther(uchar *p, JumpPointtypedef *Q, uchar type, int Start)
{
    int i = 0;
      if (type == 0) {
        for (i = (Start - 1); i >= 1; i--) {
          if (*(p + i) == 0 && *(p + i + 1) != 0) {
            Q->point = i;
            Q->type = 'T';
            break;
          } else if (i == 1) {
            Q->point = i;
            Q->type = 'W';
            break;
          }
        }
      } else if (type == 1) {
        for (i = (Start + 1); i <= 78; i++) {
          if (*(p + i) == 0 && *(p + i - 1) != 0) {
            Q->point = i;
            Q->type = 'T';
            break;
          } else if (i == 78) {
            Q->point = i;
            Q->type = 'W';
            break;
          }
        }
      }
}

uchar ImageProcess::DrawLinesFirst()
{
    PicTemp = Pixle[59];
      if (*(PicTemp + ImageSensorMid) == 0)  //如果底边图像中点为黑，异常情况
      {
        for (Xsite = 0; Xsite < ImageSensorMid; Xsite++)  //找左右边线
        {
          if (*(PicTemp + ImageSensorMid - Xsite) !=
              0)    //一旦找到左或右赛道到中心距离，就break
            break;  //并且记录Xsite
          if (*(PicTemp + ImageSensorMid + Xsite) != 0)
            break;
        }
        //        if (Xsite > (ImageSensorMid - 15))return 'F';
        //        //如果赛道在中点在25格以外了，那么认为无效，gg
        //                //过了上面一句说明还是有效的
        if (*(PicTemp + ImageSensorMid - Xsite) != 0)  //赛道如果在左边的话
        {
          BottomBorderRight = ImageSensorMid - Xsite + 1;  // 59行右边线有啦
          for (Xsite = BottomBorderRight; Xsite > 0; Xsite--)  //开始找59行左边线
          {
            if (*(PicTemp + Xsite) == 0 &&
                *(PicTemp + Xsite - 1) == 0)  //连续两个黑点，滤波
            {
              BottomBorderLeft = Xsite;  //左边线找到
              break;
            } else if (Xsite == 1) {
              BottomBorderLeft = 0;  //搜索到最后了，看不到左边线，左边线认为是0
              break;
            }
          }
        } else if (*(PicTemp + ImageSensorMid + Xsite) != 0)  //赛道如果在右边的话
        {
          BottomBorderLeft = ImageSensorMid + Xsite - 1;  // 59行左边线有啦
          for (Xsite = BottomBorderLeft; Xsite < 79; Xsite++)  //开始找59行左边线
          {
            if (*(PicTemp + Xsite) == 0 &&
                *(PicTemp + Xsite + 1) == 0)  //连续两个黑点，滤波
            {
              BottomBorderRight = Xsite;  //右边线找到
              break;
            } else if (Xsite == 78) {
              BottomBorderRight = 79;  //搜索到最后了，看不到右边线，左边线认为是79
              break;
            }
          }
        }
      } else  //左边线中点是白的，比较正常的情况
      {
        for (Xsite = ImageSensorMid; Xsite < 79;
             Xsite++)  //一个点一个点地搜索右边线
        {
          if (*(PicTemp + Xsite) == 0 &&
              *(PicTemp + Xsite + 1) == 0)  //连续两个黑点，滤波
          {
            BottomBorderRight = Xsite;  //找到就记录
            break;
          } else if (Xsite == 78) {
            BottomBorderRight = 79;  //找不到认为79
            break;
          }
        }
        for (Xsite = ImageSensorMid; Xsite > 0; Xsite--)  //一个点一个点地搜索左边线
        {
          if (*(PicTemp + Xsite) == 0 &&
              *(PicTemp + Xsite - 1) == 0)  //连续两个黑点，滤波
          {
            BottomBorderLeft = Xsite;  //找到就记录
            break;
          } else if (Xsite == 1) {
            BottomBorderLeft = 0;  //找不到认为0
            break;
          }
        }
      }
      BottomCenter =(BottomBorderLeft + BottomBorderRight) / 2;  // 59行中点直接取平均
      ImageDeal[59].LeftBorder =BottomBorderLeft;  //在数组里面记录一下信息，第一行特殊一点而已
      ImageDeal[59].RightBorder = BottomBorderRight;
      ImageDeal[59].Center = BottomCenter;  ////确定最底边
      ImageDeal[59].Wide = BottomBorderRight - BottomBorderLeft;  /////存储宽度信息
      ImageDeal[59].IsLeftFind = 'T';
      ImageDeal[59].IsRightFind = 'T';
      for (Ysite = 58; Ysite > 54; Ysite--)  ////由中间向两边确定底边五行
      {
        PicTemp = Pixle[Ysite];
        for (Xsite = ImageDeal[Ysite + 1].Center; Xsite < 79;
             Xsite++)  //和前面一样的搜索
        {
          if (*(PicTemp + Xsite) == 0 && *(PicTemp + Xsite + 1) == 0) {
            ImageDeal[Ysite].RightBorder = Xsite;
            break;
          } else if (Xsite == 78) {
            ImageDeal[Ysite].RightBorder = 79;
            break;
          }
        }
        for (Xsite = ImageDeal[Ysite + 1].Center; Xsite > 0;
             Xsite--)  //和前面一样的搜索
        {
          if (*(PicTemp + Xsite) == 0 && *(PicTemp + Xsite - 1) == 0) {
            ImageDeal[Ysite].LeftBorder = Xsite;
            break;
          } else if (Xsite == 1) {
            ImageDeal[Ysite].LeftBorder = 0;
            break;
          }
        }
        ImageDeal[Ysite].IsLeftFind = 'T';  //这些信息存储到数组里
        ImageDeal[Ysite].IsRightFind = 'T';
        ImageDeal[Ysite].Center =(ImageDeal[Ysite].RightBorder + ImageDeal[Ysite].LeftBorder) /2;  //存储中点
        ImageDeal[Ysite].Wide = ImageDeal[Ysite].RightBorder - ImageDeal[Ysite].LeftBorder;  //存储宽度
      }
      return 'T';
}

void ImageProcess::DrawLinesProcess()
{
      uchar L_Found_T = 'F';  //确定无边斜率的基准有边行是否被找到的标志
      uchar Get_L_line = 'F';  //找到这一帧图像的基准左斜率
      uchar R_Found_T = 'F';  //确定无边斜率的基准有边行是否被找到的标志
      uchar Get_R_line = 'F';  //找到这一帧图像的基准右斜率
      float D_L = 0;           //延长线左边线斜率
      float D_R = 0;           //延长线右边线斜率
      int ytemp_W_L;           //记住首次左丢边行
      int ytemp_W_R;           //记住首次右丢边行
      ExtenRFlag = 0;          //标志位清0
      ExtenLFlag = 0;
      for (Ysite = 54 /*54*/; Ysite > ImageStatus.OFFLine;
           Ysite--)  //前5行处理过了，下面从55行到（设定的不处理的行OFFLine）
      {  //太远的图像不稳定，OFFLine以后的不处理
        PicTemp = Pixle[Ysite];
        JumpPointtypedef JumpPoint[2];  // 0左1右
        if (ImageStatus.Road_type != Cross) {
          IntervalLow =
              ImageDeal[Ysite + 1].RightBorder -
              ImageScanInterval;  //从上一行右边线-5的点开始（确定扫描开始点）
          IntervalHigh =
              ImageDeal[Ysite + 1].RightBorder +
              ImageScanInterval;  //到上一行右边线+5的点结束（确定扫描结束点）
        } else {
          IntervalLow =
              ImageDeal[Ysite + 1].RightBorder -
              ImageScanInterval_Cross;  //从上一行右边线-5的点开始（确定扫描开始点）
          IntervalHigh = ImageDeal[Ysite + 1].RightBorder + ImageScanInterval_Cross;
        }

        LimitL(IntervalLow);   //确定左扫描区间并进行限制
        LimitH(IntervalHigh);  /////确定右扫描区间并进行限制
        GetJumpPointFromDet(PicTemp, 'R', IntervalLow, IntervalHigh,
                            &JumpPoint[1]);  //扫右边线

        IntervalLow =
            ImageDeal[Ysite + 1].LeftBorder -
            ImageScanInterval;  //从上一行左边线-5的点开始（确定扫描开始点）
        IntervalHigh =
            ImageDeal[Ysite + 1].LeftBorder +
            ImageScanInterval;  //到上一行左边线+5的点结束（确定扫描结束点）

        LimitL(IntervalLow);   //确定左扫描区间并进行限制
        LimitH(IntervalHigh);  //确定右扫描区间并进行限制
        GetJumpPointFromDet(PicTemp, 'L', IntervalLow, IntervalHigh,
                            &JumpPoint[0]);  //

        if (JumpPoint[0].type ==
            'W')  //如果本行左边线不正常跳变，即这10个点都是白的
        {
          ImageDeal[Ysite].LeftBorder =
              ImageDeal[Ysite + 1].LeftBorder;  //本行左边线用上一行的数值
        } else                                  //左边线正常
        {
          ImageDeal[Ysite].LeftBorder = JumpPoint[0].point;  //记录下来啦
        }

        if (JumpPoint[1].type == 'W')  //如果本行右边线不正常跳变
        {
          ImageDeal[Ysite].RightBorder =
              ImageDeal[Ysite + 1].RightBorder;  //本行右边线用上一行的数值
        } else                                   //右边线正常
        {
          ImageDeal[Ysite].RightBorder = JumpPoint[1].point;  //记录下来啦
        }

        ImageDeal[Ysite].IsLeftFind =
            JumpPoint[0].type;  //记录本行是否找到边线，即边线类型
        ImageDeal[Ysite].IsRightFind = JumpPoint[1].type;

        ///////重新确定那些大跳变的边缘
        if ((ImageDeal[Ysite].IsLeftFind == 'H' ||
             ImageDeal[Ysite].IsRightFind == 'H')) {
          if (ImageDeal[Ysite].IsLeftFind == 'H')  //如果左边线大跳变
            for (Xsite = (ImageDeal[Ysite].LeftBorder + 1);
                 Xsite <= (ImageDeal[Ysite].RightBorder - 1);
                 Xsite++)  //左右边线之间重新扫描
            {
              if ((*(PicTemp + Xsite) == 0) && (*(PicTemp + Xsite + 1) != 0)) {
                ImageDeal[Ysite].LeftBorder =
                    Xsite;  ////如果上一行左边线的右边有黑白跳变则为绝对边线直接取出
                ImageDeal[Ysite].IsLeftFind = 'T';
                break;
              } else if (*(PicTemp + Xsite) != 0)  ///一旦出现白点则直接跳出
                break;
              else if (Xsite ==
                       (ImageDeal[Ysite].RightBorder - 1))  //??????????????
              {
                ImageDeal[Ysite].LeftBorder = Xsite;
                ImageDeal[Ysite].IsLeftFind = 'T';
                break;
              }
            }
          if ((ImageDeal[Ysite].RightBorder - ImageDeal[Ysite].LeftBorder) <=
              7)  ///////图像宽度限定
          {
            ImageStatus.OFFLine = Ysite + 1;  //如果这行比7小了后面直接不要了
            break;
          }
          if (ImageDeal[Ysite].IsRightFind == 'H')
            for (Xsite = (ImageDeal[Ysite].RightBorder - 1);
                 Xsite >= (ImageDeal[Ysite].LeftBorder + 1); Xsite--) {
              if ((*(PicTemp + Xsite) == 0) && (*(PicTemp + Xsite - 1) != 0)) {
                ImageDeal[Ysite].RightBorder =
                    Xsite;  ////如果右边线的左边还有黑白跳变则为绝对边线直接取出
                ImageDeal[Ysite].IsRightFind = 'T';
                break;
              } else if (*(PicTemp + Xsite) != 0)
                break;
              else if (Xsite == (ImageDeal[Ysite].LeftBorder + 1))  //?????
              {
                ImageDeal[Ysite].RightBorder = Xsite;
                ImageDeal[Ysite].IsRightFind = 'T';
                break;
              }
            }
        }

        //        /***********重新确定无边行************/
        int ysite = 0;
        int L_found_point = 0;
        int R_found_point = 0;

        if (    ImageDeal[Ysite].IsRightFind == 'W'
              &&Ysite > 10
              &&Ysite < 50
            )  //最早出现的无边行
        {
          if (Get_R_line == 'F')  //这一帧图像没有跑过这个找基准线循环
          {
            Get_R_line = 'T';       //找了  一帧图像只跑一次 置为T
            ytemp_W_R = Ysite + 2;  //
            for (ysite = Ysite + 1; ysite < Ysite + 15; ysite++) {
              if (ImageDeal[ysite].IsRightFind ==
                  'T')  //往无边行下面搜索  一般都是有边的
                R_found_point++;
            }
            if (R_found_point >
                8)  //找到基准斜率边  做延长线重新确定无边   当有边的点数大于8
            {
              D_R = ((float)(ImageDeal[Ysite + R_found_point].RightBorder -
                             ImageDeal[Ysite + 3].RightBorder)) /
                    ((float)(R_found_point - 3));  //求下面这些点连起来的斜率
                                                   //好给无边行做延长线左个基准
              if (D_R > 0) {
                R_Found_T =
                    'T';  //如果斜率大于0  那么找到了这个基准行  因为梯形畸变
                          //所以一般情况都是斜率大于  小于0的情况也不用延长 没必要

              } else {
                R_Found_T = 'F';  //没有找到这个基准行
                if (D_R < 0)
                  ExtenRFlag = 'F';  //这个标志位用于十字角点补线  防止图像误补用的
              }
            }
          }

          //                    f5=R_Found_T;//用于蓝牙发送标志位
          //                    gpio_set(P21_5,0);//用于调试
          if (R_Found_T == 'T')
            ImageDeal[Ysite].RightBorder =
                ImageDeal[ytemp_W_R].RightBorder -
                D_R * (ytemp_W_R - Ysite);  //如果找到了 那么以基准行做延长线

          LimitL(ImageDeal[Ysite].RightBorder);  //限幅
          LimitH(ImageDeal[Ysite].RightBorder);  //限幅
        }

        if (ImageDeal[Ysite].IsLeftFind == 'W' && Ysite > 10 && Ysite < 50 &&
            ImageStatus.Road_type != Barn_in)  //下面同理  左边界
        {
          if (Get_L_line == 'F') {
            Get_L_line = 'T';
            ytemp_W_L = Ysite + 2;
            for (ysite = Ysite + 1; ysite < Ysite + 15; ysite++) {
              if (ImageDeal[ysite].IsLeftFind == 'T')
                L_found_point++;
            }
            if (L_found_point > 8)  //找到基准斜率边  做延长线重新确定无边
            {
              D_L = ((float)(ImageDeal[Ysite + 3].LeftBorder -
                             ImageDeal[Ysite + L_found_point].LeftBorder)) /
                    ((float)(L_found_point - 3));
              if (D_L > 0) {
                L_Found_T = 'T';

              } else {
                L_Found_T = 'F';
                if (D_L < 0)
                  ExtenLFlag = 'F';
              }
            }
          }

          if (L_Found_T == 'T')
            ImageDeal[Ysite].LeftBorder =
                ImageDeal[ytemp_W_L].LeftBorder + D_L * (ytemp_W_L - Ysite);

          LimitL(ImageDeal[Ysite].LeftBorder);  //限幅
          LimitH(ImageDeal[Ysite].LeftBorder);  //限幅
        }


        if (ImageDeal[Ysite].IsLeftFind == 'W' &&
            ImageDeal[Ysite].IsRightFind == 'W')
          ImageStatus.WhiteLine++;  //要是左右都无边，丢边数+1

        LimitL(ImageDeal[Ysite].LeftBorder);   //限幅
        LimitH(ImageDeal[Ysite].LeftBorder);   //限幅
        LimitL(ImageDeal[Ysite].RightBorder);  //限幅
        LimitH(ImageDeal[Ysite].RightBorder);  //限幅

        ImageDeal[Ysite].Wide =
            ImageDeal[Ysite].RightBorder - ImageDeal[Ysite].LeftBorder;
        ImageDeal[Ysite].Center =
            (ImageDeal[Ysite].RightBorder + ImageDeal[Ysite].LeftBorder) / 2;

        if (ImageDeal[Ysite].Wide <= 7)  //重新确定可视距离
        {
          ImageStatus.OFFLine = Ysite + 1;
          break;
        }

        else if (ImageDeal[Ysite].RightBorder <= 10 ||
                 ImageDeal[Ysite].LeftBorder >= 70) {
          ImageStatus.OFFLine = Ysite + 1;
          break;
        }  //当图像宽度小于0或者左右边达到一定的限制时，则终止巡边
      }


      return;
}

void ImageProcess::DrawLine()
{
//    int i;
//    for(i=59;i>ImageStatus.OFFLine;i--)
//    {
//      Pixle[i][ImageDeal[i].LeftBorder+2]=0;//移动两位便于观察
//      Pixle[i][ImageDeal[i].RightBorder-2]=0;
//      Pixle[i][ImageDeal[i].Center]=0;
//    }
}

