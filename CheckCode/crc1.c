#include <stdio.h>
#include <inttypes.h>
/****
  数据滑动，crc不动
  */
uint16_t crc16_div_1()
{
    uint32_t data = 0x88;
    uint32_t ccitt16 = 0x11021;//17位

    //对齐到32位
    data <<= 24;//确保比ccitt16大,且有效位与int对齐
    ccitt16<<=15; // sizeof(int) - sizeof(ccitt16) = 32-17=15
    for (int i=0; i<8; i++)
    {
        // 如果data的msb是1的话，说明data移到位了！
        if (data & 0x80000000/*0x80000000、data和ccitt16都对齐到32位*/) 
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
int main(void)
{
    uint16_t crc=crc16_div_1();
    printf("crc is %x\n", crc);
}
// 输出：
// crc is 1080
