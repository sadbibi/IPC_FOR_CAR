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
#pragma section all "cpu0_dsram"
//���������#pragma section all restore���֮���ȫ�ֱ���������CPU0��RAM��


//���̵��뵽���֮��Ӧ��ѡ�й���Ȼ����refreshˢ��һ��֮���ٱ���
//����Ĭ������Ϊ�ر��Ż��������Լ��һ�����ѡ��properties->C/C++ Build->Setting
//Ȼ�����Ҳ�Ĵ������ҵ�C/C++ Compiler->Optimization->Optimization level�������Ż��ȼ�
//һ��Ĭ���½����Ĺ��̶���Ĭ�Ͽ�2���Ż�����˴��Ҳ��������Ϊ2���Ż�

//����TCϵ��Ĭ���ǲ�֧���ж�Ƕ�׵ģ�ϣ��֧���ж�Ƕ����Ҫ���ж���ʹ��enableInterrupts();�������ж�Ƕ��
//�򵥵�˵ʵ���Ͻ����жϺ�TCϵ�е�Ӳ���Զ�������disableInterrupts();���ܾ���Ӧ�κε��жϣ������Ҫ�����Լ��ֶ�����enableInterrupts();�������жϵ���Ӧ��


#define IPCH 60//��λ����ʾͼ��߶�
#define IPCW 80//��λ����ʾͼ����
#define RED 1
#define BLUE 2
#define YELLOW 3
#define GREEN 4


float Mh = MT9V03X_H;
float Lh = IPCH;
float Mw = MT9V03X_W;
float Lw = IPCW;
uint8    Image_Use[IPCH][IPCW];


void Compressimage() {
  int i, j, row, line;
  const float div_h = Mh / Lh, div_w = Mw / Lw;
  for (i = 0; i < IPCH; i++) {
    row = i * div_h + 0.5;
    for (j = 0; j < IPCW; j++) {
      line = j * div_w + 0.5;
      Image_Use[i][j] = mt9v03x_image[row][line];

      //��ɫ����
//      if(i==10)
//          Image_Use[i][j]=RED;
//      if(i==20)
//          Image_Use[i][j]=BLUE;
//      if(i==30)
//          Image_Use[i][j]=YELLOW;
//      if(i==40)
//          Image_Use[i][j]=GREEN;

    }
  }
   //ʹ����һ֡DMA�����ͼ��ͼ��  ���Կ�ʼ������һ֡
}

int core0_main(void)
{
    disableInterrupts();
	get_clk();//��ȡʱ��Ƶ��  ��ر���
	//�û��ڴ˴����ø��ֳ�ʼ��������
    mt9v03x_init();
    picoLinkInit_Uart();
    ips114_init();


	int n;
	int t;
    //�ȴ����к��ĳ�ʼ�����
	IfxCpu_emitEvent(&g_cpuSyncEvent);
	IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
	enableInterrupts();


	while (TRUE)
	{
        if(mt9v03x_finish_flag==1){

            Compressimage();
            ipcSendImage_Uart(Image_Use);
            mt9v03x_finish_flag = 0;
//            //systick_start(STM0);
//            seekfree_wireless_send_buff("CSU",3);
//            seekfree_wireless_send_buff(Image_Use[0],IPCH*IPCW);
//            seekfree_wireless_send_buff("USC",3);

//            ips114_displayimage032(Image_Use[0],IPCW,IPCH);
//            uart_putbuff(WIRELESS_UART,"CSU",3);
 //           seekfree_sendimg_03x(WIRELESS_UART,Image_Use[0],90,60);
//            uart_putbuff(WIRELESS_UART,"USC",3);

//            t=systick_getval_us(STM0);
//            //uart_putbuff(DEBUG_UART,"c",1);
//            printf("%d",t);

        }




	}
}

#pragma section all restore


