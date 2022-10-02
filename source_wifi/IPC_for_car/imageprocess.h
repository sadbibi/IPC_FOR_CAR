#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H
#include <QDebug>
#include <QObject>
#include <QWidget>
#define LCDH 60                              //用于图像处理图像的高度
#define LCDW 80                              //用于图像处理图像的宽度
#define uLCDH 120                            //用于图像显示的图像高度
#define uLCDW 160                            //用于图像显示的图像宽度
#define LimitL(L) (L = ((L < 1) ? 1 : L))    //限制幅度
#define LimitH(H) (H = ((H > 78) ? 78 : H))  //限制幅度
#define ImageSensorMid 39                    //图像屏幕中点

#define RED 1
#define BLUE 2
#define YELLOW 3
#define GREEN 4

class JumpPointtypedef{
public:
  int point;
  char type;
};

//每一行的属性
class ImageDealDatatypedef {
public:
  /*左右边边界标志    T为正常跳变边    W为无边   P为障碍类多跳边的内边*/
  char IsRightFind;
  char IsLeftFind;
  char isBlackFind;
  int Wide;               //边界宽度
  int LeftBorder;         //左边界
  int RightBorder;        //右边界
  int close_LeftBorder;   //靠边边界
  int close_RightBorder;  //靠边边界
  int opp_LeftBorder;     //反向边界
  int opp_RightBorder;    //反向边界
  int Center;             //中线
  int RightTemp;          //右边临时值
  int LeftTemp;           //左边临时值
  int CenterTemp;         //中线临时值
  int Black_Point;        //单行黑点数量

  // fork   下面的变量用于岔路口的检测
  int BlackWide;     //三叉口黑色宽度
  int Black_Wide_L;  //三叉口黑色左边
  int Black_Wide_R;  //三叉口黑色右边
  int Black_Pro;     //三叉口黑点比例

  int mid_temp;  //中线临时值



};

//元素类型
typedef enum {
  Normol,       //无任何特征
  Straight,     //直道
  Cross,        //十字
  Ramp,         //坡道
  LeftCirque,   //左圆环
  RightCirque,  //右圆环
  Forkin,       //岔路进口
  Forkout,      //岔路出口
  Barn_out,     //出库
  Barn_in,      //入库
  Cross_ture,


} RoadType_e;



class ImageStatustypedef {
  /*以下关于全局图像正常参数*/

  //图像信息
public:
  int TowPoint;             //初始比较点   给定前瞻
  int TowPointAdjust_v;     //初始比较点适应速度  没用
  int TowPoint_True;        //实际比较点               没用
  int TowPoint_Gain;        //增益系数                   没用
  int TowPoint_Offset_Max;  //最大偏置系数         没用
  int TowPoint_Offset_Min;  //最小偏置系数          没用
  int Det_True;             //由GetDet()函数解算出来的平均图像偏差
  int Det_all;              //图像的近端到远端的总偏差
  float Det_all_k;          //斜率

  int Threshold;          //二值化阈值
  int Threshold_static;  //二值化静态下限
  int Threshold_detach;   //阳光算法分割阈值
  int MiddleLine;         //屏幕中心
  int Foresight;            //偏差速度因子   远端的偏差  用于控速
  int OFFLine;            //图像顶边
  int WhiteLine;          //双边丢边数
  float ExpectCur;          //图像期望曲率       没用
  float White_Ritio;        //有效行白点比例     没用
  int Black_Pro_ALL;        //整体黑点比例%    没用

  // PID
  float Piriod_P;  //分段P   值     没用
  float MU_P;

  RoadType_e Road_type;  //元素类型

  /****圆环***/
  char IsCinqueOutIn;  //进出圆环
  char CirquePass;     //圆环中
  char CirqueOut;      //出圆环
  char CirqueOff;      //圆环结束
  int Pass_Lenth;       //入环距离  用于防抖
                        /****圆环***/

  int Out_Lenth;     //
  int Fork_Out_Len;  //出岔口防抖
  int Dowm_lenth;    //三叉减速距离  //g5.13
  int Cross_Lenth;  // 270°转过之后一般是十字路口   作为三岔口的消抖
  int Cross_ture_lenth;
  int Sita;  //据此判断在过去一段路程中转过多少角度

  //车库
  int Barn_Flag;   //判断库的次数
  int Barn_Lenth;  //入库停止距离

  //保护
  int Stop_lenth;  //出界保护放误判距离
  //坡道减速
  int Ramp_lenth;

  int variance;  //直道检测阈值方差

  int straight_acc;  //直道加速标志位
  int  variance_acc;    //用于加速的阈值方差

  int ramptestlenth;//坡道检测间隔
} ;

class ImageProcess : public QWidget
{


    Q_OBJECT
public:
    explicit ImageProcess(QWidget *parent = nullptr);
    uchar *  Imageprocess(uchar * origPic);

signals:

public slots:

private:

       void imageInit(uchar *Pic);
       void Get01change_dajin();  //图像二值化
       int  Threshold_deal(uchar* image,int col,int row,int pixel_threshold);
       void Pixle_Filter();
       void GetJumpPointFromDet(uchar* p,uchar type,int L,int H,JumpPointtypedef* Q);
       void GetJumpPointFromCenter(uchar* p,JumpPointtypedef* L,JumpPointtypedef* R,int Center);
       void GetJumpPointFromOther(uchar* p,JumpPointtypedef* Q,uchar type,int Start);
       uchar DrawLinesFirst(void);
       void DrawLinesProcess(void);
       void DrawExtensionLine();  //得到延长线 8us

};



#endif // IMAGEPROCESS_H
