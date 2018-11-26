#include <stdio.h>
#include <inttypes.h>

/*********
 * [in] unsigned char data, 数据流中的一个byte
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
void main()
{
    uint16_t crc;

    // 兼容单字节
    crc = crc16_ccitt(0x88, 0);
    printf("crc is %x\n", crc);

    // 多字节测试
    uint8_t data[5] = { 0x71, 0x88, 0x93, 0xa5, 0x13 };
    crc = 0;
    for (int i=0; i<5; i++)
    {
        crc = crc16_ccitt(data[i], crc);
    }
    printf("crc is %x\n", crc);
}
// 输出：
// crc is 1080
// crc is e9c
