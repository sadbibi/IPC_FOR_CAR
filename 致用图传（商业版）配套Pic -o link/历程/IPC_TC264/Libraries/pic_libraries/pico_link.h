#ifndef _PICO_LINK_H__
#define _PICO_LINK_H__

//数据类型声明
typedef unsigned char pico_uint8;      //  8 bits
typedef unsigned long int pico_uint32; // 32 bits

#define DEVICE_TC264 //目标芯片名称

#if (defined DEVICE_TC264) || (defined DEVICE_RT1064)

#include "zf_uart.h"
#include "zf_spi.h"
#include "zf_gpio.h"
#include "SEEKFREE_WIRELESS.h"

#define UART_PORT (WIRELESS_UART) //串口端口默认配置和逐飞无线串口接口相同
#define UART_TXD (WIRELESS_UART_TX)
#define UART_RXD (WIRELESS_UART_RX)
#define UART_CTS (RTS_PIN)

#define uartWriteBuff uart_putbuff

#elif (defined DEVICE_MM32) // MM32请使用最新的逐飞库

#include "zf_driver_uart.h"
#include "zf_driver_spi.h"
#include "zf_driver_gpio.h"
#include "zf_device_wireless_uart.h"

#define UART_PORT (WRIELESS_UART_INDEX) //串口端口默认配置和逐飞无线串口接口相同
#define UART_TXD (WRIELESS_UART_RX_PIN)
#define UART_RXD (WRIELESS_UART_TX_PIN)
#define UART_CTS (WRIELESS_UART_RTS_PIN)

#define uartWriteBuff uart_write_buffer

#endif

#define IMAGE_H (60) //发送图像高度，一定要和实际发送的图像高度相同
#define IMAGE_W (80) //发送图像宽度，一定要和实际发送的图像宽度相同

#define HAS_CTS_PIN (1) //是否接了流控引脚

#define UART_BAUD (3000000) // UART波特率
#define SPI_BAUD (10000000) // SPI波特率
//下列参数根据单片机型号自行定义
#define SPI_NUM (SPI_0)
#define SPI_SCK_PIN (SPI0_SCLK_P20_11)                          //CLK
#define SPI_MOSI_PIN (SPI0_MOSI_P20_14)                         //MOSI
#define SPI_MISO_PIN (SPI0_MISO_P20_12)                         //MISO
#define SPI_CS_PIN (SPI0_CS2_P20_13)                           //CS
#define IPC_SPI_BASE_LEN  (IMAGE_H * IMAGE_W + 6)                //
#define IPC_SPI_FINAL_LEN (IPC_SPI_BASE_LEN + 4 - IPC_SPI_BASE_LEN % 4)
void picoLinkInit_Uart(void);
void ipcSendImage_Uart(pico_uint8 *pImage);
void picoLinkInit_Spi(void);
void ipcSendImage_Spi(pico_uint8 *pImage);

#endif
