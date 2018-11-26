#include <stdio.h>
#include <inttypes.h>

/* (gdb) help x */
/* (gdb) display/t data */

uint16_t crc16_div()
{
    uint32_t data = 0x880000; //将单字节数据0x88左移16位得到的。
    uint32_t ccitt16 = 0x11021;//除数
    uint32_t cmp_value = 0x10000;

    ccitt16 <<= 7;
    cmp_value <<= 7;
    while (cmp_value >= 0x10000)
    {
        if ((data & cmp_value) != 0)
        {
            data ^= ccitt16;
        }
        else
        {

        }

        ccitt16 >>= 1;
        cmp_value >>= 1;
    }
    data &=0xFFFF;

    return (data^0x0000);
}
uint16_t crc16_div_1()
{
    uint32_t data = 0x88;
    uint32_t ccitt16 = 0x11021;
    data <<= 24;//确保比ccitt16大,且有效位与int对齐
    ccitt16<<=15; // sizeof(int) - sizeof(ccitt16) = 32-17=15
    for (int i=0; i<8; i++)
    {
        if (data & 0x80000000) // 如果data的msb是1的话
        {
            data ^= ccitt16;
        }
        else
        {
            data <<= 1;
        }
    }
    return (data>>15);//将余数右移回来
}
uint16_t crc16_div_2()
{
    uint16_t data = 0x88;
    uint16_t ccitt16 = 0x1021;
    data <<= 8;
    for (int i=0; i<8; i++)
    {
        if (data & 0x8000) // 如果data的msb是1的话
        {
            data <<= 1;
            data ^= ccitt16;
        }
        else
        {
            data <<= 1;
        }
    }
    return data;
}
uint16_t crc16_ccitt(uint8_t data, uint16_t crc)
{
    uint16_t ccitt16 = 0x1021;
    crc ^= (data<<8);

    for (int i=0; i<8; i++)
    {
        //注意不能将if-else语句中的"crc<<1;"提出来，
        //放在if语句的前头，因为这会影响crc&8000这个条件的判断
        if (crc & 0x8000)
        {
            crc <<= 1;
            crc ^= ccitt16;
        }
        else
        {
            crc <<= 1;
        }
    }
    return crc;
}

void main()
{
    uint16_t crc=crc16_div();
    printf("crc is %x\n", crc);

    crc = crc16_div_1();
    printf("crc is %x\n", crc);

    crc = crc16_div_2();
    printf("crc is %x\n", crc);

    crc = crc16_ccitt(0x88, 0);
    printf("crc is %x\n", crc);

    char data[5] = { 0x71, 0x88, 0x93, 0xa5, 0x13 };//MSB先处理
    crc = 0;
    for (int i=0; i<5; i++)
    {
        crc = crc16_ccitt(data[i], crc);
    }
    printf("crc is %x\n", crc);


    // 假设发送端接受到的数据为data2
    uint8_t data2[7];
    for(int i=0; i<5; ++i) 
    {
        data2[i]=data[i];
    }
    uint16_t crc1 = crc & 0xFF00;//取高位
    crc1>>=8;
    data2[5] = crc1;//先处理MSB
    char crc0 = crc & 0x00FF;//取低8位
    data2[6]=crc0;//再处理LSB
    printf("The sender sent:\t");
    for(int i=0; i<7; ++i) printf("%02x ", data2[i]);
    printf("\n");


    // 假设接收端接受到的数据为data2
    // 并且传输过程中没有发生任何错误。
    printf("The receiver got:\t");
    for(int i=0; i<7; ++i) printf("%02x ", data2[i]);
    printf("\n");

    // 对传输得到的data2进行检验
    crc=0;
    for (int i=0; i<7; i++)
    {
        crc = crc16_ccitt(data2[i], crc);
    }
    printf("crc is %x\n", crc);// must be zero, or error occured during transportation

}

/****
 * https://blog.csdn.net/leumber/article/details/54311811
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void InvertUint8(uint8_t *dBuf,uint8_t *srcBuf);
void InvertUint16(uint16_t *dBuf,uint16_t *srcBuf);
void InvertUint32(uint32_t *dBuf,uint32_t *srcBuf);

uint16_t CRC16_CCITT(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0x0000;
    uint16_t wCPoly = 0x1021;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        InvertUint8(&wChar,&wChar);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    InvertUint16(&wCRCin,&wCRCin);
    return (wCRCin) ;
}
uint16_t CRC16_CCITT_FALSE(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0xFFFF;
    uint16_t wCPoly = 0x1021;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    return (wCRCin) ;
}
uint16_t CRC16_XMODEM(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0x0000;
    uint16_t wCPoly = 0x1021;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    return (wCRCin) ;
}

uint16_t CRC16_X25(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0xFFFF;
    uint16_t wCPoly = 0x1021;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        InvertUint8(&wChar,&wChar);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    InvertUint16(&wCRCin,&wCRCin);
    return (wCRCin^0xFFFF) ;
}

uint16_t CRC16_MODBUS(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0xFFFF;
    uint16_t wCPoly = 0x8005;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        InvertUint8(&wChar,&wChar);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    InvertUint16(&wCRCin,&wCRCin);
    return (wCRCin) ;
}
uint16_t CRC16_IBM(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0x0000;
    uint16_t wCPoly = 0x8005;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        InvertUint8(&wChar,&wChar);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    InvertUint16(&wCRCin,&wCRCin);
    return (wCRCin) ;
}
uint16_t CRC16_MAXIM(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0x0000;
    uint16_t wCPoly = 0x8005;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        InvertUint8(&wChar,&wChar);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    InvertUint16(&wCRCin,&wCRCin);
    return (wCRCin^0xFFFF) ;
}
uint16_t CRC16_USB(uint8_t *puchMsg, uint32_t usDataLen)
{
    uint16_t wCRCin = 0xFFFF;
    uint16_t wCPoly = 0x8005;
    uint8_t wChar = 0;

    while (usDataLen--)  
    {
        wChar = *(puchMsg++);
        InvertUint8(&wChar,&wChar);
        wCRCin ^= (wChar << 8);
        for(int i = 0;i < 8;i++)
        {
            if(wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    InvertUint16(&wCRCin,&wCRCin);
    return (wCRCin^0xFFFF) ;
}

void InvertUint8(uint8_t *dBuf,uint8_t *srcBuf)
{
    int i;
    uint8_t tmp[4];
    tmp[0] = 0;
    for(i=0;i< 8;i++)
    {
        if(srcBuf[0]& (1 << i))
            tmp[0]|=1<<(7-i);
    }
    dBuf[0] = tmp[0];

}
void InvertUint16(uint16_t *dBuf,uint16_t *srcBuf)
{
    int i;
    uint16_t tmp[4];
    tmp[0] = 0;
    for(i=0;i< 16;i++)
    {
        if(srcBuf[0]& (1 << i))
            tmp[0]|=1<<(15 - i);
    }
    dBuf[0] = tmp[0];
}
void InvertUint32(uint32_t *dBuf,uint32_t *srcBuf)
{
    int i;
    uint32_t tmp[4];

    tmp[0] = 0;

    for(i=0;i< 32;i++)
    {
        if(srcBuf[0]& (1 << i))
            tmp[0]|=1<<(15 - i);
    }
    dBuf[0] = tmp[0];
}

/* (gdb) display/t data */
/*
int main(void)
{
    uint8_t puchMsg[]={0x67, 0x34, 0x32, 0x67, 0x34};
    uint32_t len = sizeof puchMsg;
    uint16_t result = CRC16_MODBUS(puchMsg, len); 

    printf( "crc=%x\n", result);//0xd095

    return 0;
}
********/
