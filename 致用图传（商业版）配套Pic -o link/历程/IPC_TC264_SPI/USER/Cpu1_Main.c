/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		ADS v1.2.2
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/

#include "headfile.h"
#pragma section all "cpu1_dsram"
//���������#pragma section all restore���֮���ȫ�ֱ���������CPU1��RAM��
//#define IPCH 60//��λ����ʾͼ��߶�
//#define IPCW 90//��λ����ʾͼ����
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
//      //��ɫ����
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
//   //ʹ����һ֡DMA�����ͼ��ͼ��  ���Կ�ʼ������һ֡
//}

void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    //�û��ڴ˴����ø��ֳ�ʼ��������


//    mt9v03x_init();
//    seekfree_wireless_init();
//    ips114_init();        // ��ʼ��IPS��Ļ

    int n;
	//�ȴ����к��ĳ�ʼ�����
	IfxCpu_emitEvent(&g_cpuSyncEvent);
	IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();
    while (TRUE)
    {
		//�û��ڴ˴���д�������
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
