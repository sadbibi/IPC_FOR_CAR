/*
 * @Author: your name
 * @Date: 2022-03-20 17:56:13
 * @LastEditTime: 2022-07-02 15:49:10
 * @LastEditors: Wanderer-web
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \MDKd:\MyProjects\IPC-WIFI-example\rt1064\RT1064_SPI_NEW\Project\USER\src\main.c
 */
/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.28
 * @Target core		NXP RT1064DVL6A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-30
 ********************************************************************************************************************/

//�����Ƽ�IO�鿴Projecct�ļ����µ�TXT�ı�

//���µĹ��̻��߹����ƶ���λ�����ִ�����²���
//��һ�� �ر��������д򿪵��ļ�
//�ڶ��� project  clean  �ȴ��·�����������

//���ش���ǰ������Լ�ʹ�õ��������ڹ���������������Ϊ�Լ���ʹ�õ�

#include "headfile.h"
#include "pico_link.h"

int main(void)
{
    DisableGlobalIRQ();
    board_init(); //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���

    //�˴���д�û�����(���磺�����ʼ�������)
    picoLinkInit_Spi();
    mt9v03x_csi_init();

    systick_delay_ms(1000);
    //���ж������
    EnableGlobalIRQ(0);

    while (1)
    {
        if (mt9v03x_csi_finish_flag)
        {
            ipcSendImage_Spi(mt9v03x_csi_image[0], 90, 140);
            mt9v03x_csi_finish_flag = 0;
        }
    }
}
