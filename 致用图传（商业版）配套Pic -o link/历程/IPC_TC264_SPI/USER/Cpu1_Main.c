/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		ADS v1.2.2
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/

#include "headfile.h"
#pragma section all "cpu1_dsram"
//将本语句与#pragma section all restore语句之间的全局变量都放在CPU1的RAM中
//#define IPCH 60//上位机显示图像高度
//#define IPCW 90//上位机显示图像宽度
//#define RED 1
//#define BLUE 2
//#define YELLOW 3
//#define GREEN 4
//
//
//float Mh = MT9V03X_H;
//float Lh = IPCH;
//float Mw = MT9V03X_W;
//float Lw = IPCW;
//uint8    Image_Use[IPCH][IPCW];
//
//
//void Compressimage() {
//  int i, j, row, line;
//  const float div_h = Mh / Lh, div_w = Mw / Lw;
//  for (i = 0; i < IPCH; i++) {
//    row = i * div_h + 0.5;
//    for (j = 0; j < IPCW; j++) {
//      line = j * div_w + 0.5;
//      Image_Use[i][j] = mt9v03x_image[row][line];
//
//      //颜色测试
////      if(i==10)
////          Image_Use[i][j]=RED;
////      if(i==20)
////          Image_Use[i][j]=BLUE;
////      if(i==30)
////          Image_Use[i][j]=YELLOW;
////      if(i==40)
////          Image_Use[i][j]=GREEN;
//
//    }
//  }
//   //使用完一帧DMA传输的图像图像  可以开始传输下一帧
//}

void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    //用户在此处调用各种初始化函数等


//    mt9v03x_init();
//    seekfree_wireless_init();
//    ips114_init();        // 初始化IPS屏幕

    int n;
	//等待所有核心初始化完毕
	IfxCpu_emitEvent(&g_cpuSyncEvent);
	IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();
    while (TRUE)
    {
		//用户在此处编写任务代码
//        if(mt9v03x_finish_flag==1){
//
//             Compressimage();
////            //systick_start(STM0);
//            seekfree_wireless_send_buff("CSU",3);
//            seekfree_wireless_send_buff(Image_Use[0],IPCH*IPCW);
//            seekfree_wireless_send_buff("USC",3);
////            ips114_displayimage032(Image_Use[0],IPCW,IPCH);
////            uart_putbuff(WIRELESS_UART,"CSU",3);
////            seekfree_sendimg_03x(WIRELESS_UART,Image_Use[0],90,60);
////            uart_putbuff(WIRELESS_UART,"USC",3);
//            mt9v03x_finish_flag = 0;
////            t=systick_getval_us(STM0);
////            //uart_putbuff(DEBUG_UART,"c",1);
////            printf("%d",t);
//              for (int i=0;i<200;i++)
//                 for(int j =0;j<200;j++)
//                     for(int z =0;z<200;z++)
//                         n=!n;
//              ips114_showint32(0, 0,n,1);
//        }


    }
}



#pragma section all restore
