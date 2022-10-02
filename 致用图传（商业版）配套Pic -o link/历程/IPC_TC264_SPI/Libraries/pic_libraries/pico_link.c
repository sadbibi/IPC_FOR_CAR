#include "pico_link.h"
pico_uint8 ipcSpiSendBuffer[IPC_SPI_FINAL_LEN];

/**
 * @description: Pico Link 串口初始化
 * @return {*}
 */
void picoLinkInit_Uart(void)
{
#if HAS_CTS_PIN
#if (defined DEVICE_TC264)
    gpio_init(UART_CTS, GPI, 0, PULLDOWN); //初始化流控引脚
#elif (defined DEVICE_RT1064)
    gpio_init(UART_CTS, GPI, 0, PULLDOWN_100K); //初始化流控引脚
#elif (defined DEVICE_MM32)
    gpio_init(UART_CTS, GPI, 0, GPI_PULL_DOWN);
#endif
#endif
    uart_init(UART_PORT, UART_BAUD, UART_TXD, UART_RXD); //初始化串口
}

/**
 * @description: Pico Link 串口发送数据
 * @param {pico_uint8} *pBuff 数据指针
 * @param {pico_uint32} len 数据长度
 * @return {*}
 */
static void SendBuff_Uart(pico_uint8 *pBuff, pico_uint32 len)
{
#if HAS_CTS_PIN
    while (len > 60)
    {
        while (gpio_get(UART_CTS))
            ; //如果CTS为低电平，则继续发送数据
        uartWriteBuff(UART_PORT, pBuff, 60);
        pBuff += 60; //地址偏移
        len -= 60;   //数量
    }
    while (gpio_get(UART_CTS))
        ;                                 //如果CTS为低电平，则继续发送数据
    uartWriteBuff(UART_PORT, pBuff, len); //发送最后的数据
#else
    uartWriteBuff(UART_PORT, pBuff, len);
#endif
}

/**
 * @description: Pico Link 串口发送图像到致用上位机
 * @param {pico_uint8} *pImage 图像指针
 * @return {*}
 */
void ipcSendImage_Uart(pico_uint8 *pImage)
{
    SendBuff_Uart((pico_uint8 *)"CSU", 3);
    SendBuff_Uart(pImage, IMAGE_H * IMAGE_W);
    SendBuff_Uart((pico_uint8 *)"USC", 3);
}

/**
 * @description:Pico Link SPI初始化
 * @return {*}
 */
void picoLinkInit_Spi(void)
{
    pico_uint8 i;
#if (defined DEVICE_TC264) || (defined DEVICE_RT1064)
    spi_init(SPI_NUM, SPI_SCK_PIN, SPI_MOSI_PIN, SPI_MISO_PIN, SPI_CS_PIN, 3, SPI_BAUD); // SPI初始化，波特率10M
#elif (defined DEVICE_MM32)
    spi_init(SPI_NUM, 3, SPI_BAUD, SPI_SCK_PIN, SPI_MOSI_PIN, SPI_MISO_PIN, SPI_CS_PIN); // SPI初始化，波特率10M
#endif
    memset(ipcSpiSendBuffer, 0, IPC_SPI_FINAL_LEN);
    memcpy((ipcSpiSendBuffer + 1), "CSU", 3);
    memcpy((ipcSpiSendBuffer + 4 + IMAGE_H * IMAGE_W), "USC", 3);
//    for (i = 0; i < IPC_SPI_BASE_LEN % 4; i++)
//    {
//        ipcSpiSendBuffer[IPC_SPI_BASE_LEN + i] = (pico_uint8)'*'; //占位，保证发送长度为4的倍数
//    }
}

/**
 * @description:Pico Link SPI发送图像到致用上位机
 * @param {pico_uint8} *pImage 图像指针
 * @return {*}
 */
void ipcSendImage_Spi(pico_uint8 *pImage)
{
    memcpy((ipcSpiSendBuffer + 4), pImage, IMAGE_H * IMAGE_W);
#if (defined DEVICE_TC264) || (defined DEVICE_RT1064)
    spi_mosi(SPI_NUM, SPI_CS_PIN, ipcSpiSendBuffer, NULL, IPC_SPI_FINAL_LEN, 1);
#elif (defined DEVICE_MM32)
    spi_mosi(SPI_NUM, ipcSpiSendBuffer, NULL, IPC_SPI_FINAL_LEN);
#endif
}
