#include <stdio.h>
#include <inttypes.h>

/*********
 * [in] uint8_t data, 数据流中的一个byte
 * [in] uint16_t crc, 上次调用本函数获得的crc余数，首次调用应为0，或者遵守规定
 *******/
uint16_t crc16_ccitt(uint8_t data, uint16_t crc)
{
    uint16_t ccitt16 = 0x1021;

    crc ^= (data<<8);//给data的尾巴上附加上次的crc，首次这个crc就是0x0000

    for (int i=0; i<8; i++)
    {
        //注意不能将if-else语句中的"crc<<1;"提出来，
        //放在if语句的前头，因为这会影响crc&8000这个条件的判断
        if (crc & 0x8000)//如果msb是1
        {
            crc <<= 1;//删除msb
            crc ^= ccitt16;//异或
        }
        else
        {
            crc <<= 1;//删除msb
        }
    }
    return crc;//最终的余数
}

/*循环左移*/
uint16_t rol(uint16_t val, int size)
{
        uint16_t res = val << size;
            res |= val >> (16 - size);
                return res;
}
/*循环右移*/
uint16_t ror(uint16_t val, int size)
{
        uint16_t res = val >> size;
            res |= val << (16 - size);
                return res;
}
/****
int main()
{
    uint16_t x = 0x8000;
    printf("rol(%x,1)=%x\n", x, rol(x,1));
    uint16_t y = 0x8001;
    printf("rol(%x,1)=%x\n", x, ror(x,1));
    return 0;
}
***/

int main(void)
{

    // 和前面介绍的那样获得crc校验码
    uint8_t data[5] = { 0x71, 0x88, 0x93, 0xa5, 0x13 };//MSB先处理
    uint16_t crc = 0;
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
    uint16_t crc0 = crc & 0xFF00;//取高位
    crc0>>=8;
    data2[5] = crc0;//正序，先处理MSB
    uint8_t crc1 = crc & 0x00FF;//取低8位
    data2[6]=crc1;//正序，后处理LSB
    printf("The sender sent:\t");
    for(int i=0; i<7; ++i) printf("%02x ", data2[i]);
    printf("\n");

    // 假设传输过程中没有发生任何错误。
    // 这里为了方便，我们假设接收端接受到的数据也放在data2
    printf("The receiver got:\t");
    for(int i=0; i<7; ++i) printf("%02x ", data2[i]);
    printf("\n");

    // 对传输得到的data2进行检验
    crc=0;
    for (int i=0; i<7; i++)
    {
        crc = crc16_ccitt(data2[i], crc);
    }
    printf("crc is %x\n", crc);// must be zero, or error occured during transpor

    // 假设传输过程中第一个字节的msb发生了错误
    //
    data2[0] = 0x71 ^ 0x80;
    crc=0;
    for (int i=0; i<7; i++)
    {
        crc = crc16_ccitt(data2[i], crc);
    }
    printf("crc is %x\n", crc);

    /***
    crc0=crc&0xFF00;
    crc0>>=8;
    data2[0]=crc0;
    data2[1] = crc & 0x00FF;
    for(int i=0; i<2; i++)
    {
        crc = crc16_ccitt(data2[i], crc);
    }
    printf("crc is %x\n", crc);//crc is 0 
    */

    crc <<=1;
}
// 运行结果
//crc is e9c
//The sender sent:	71 88 93 a5 13 0e 9c
//The receiver got:	71 88 93 a5 13 0e 9c
//crc is 0
