#include <stdio.h>
#include <inttypes.h>
/*****
  数据不动，ccitt16滑动
  (gdb) display/t data
  (gdb) display/t ccitt16
  */

uint16_t crc16_div()
{
    // data ccitt16对齐到第24位
    uint32_t data = 0x880000; //将单字节数据0x88左移16位得到的。
    // data左移的位数，应该是ccitt16的位数减一，即17-1=16
    // 如果这里data只左移12位，则本函数的最终结果为0x108，即结果也少了4位


    uint32_t ccitt16 = 0x11021;//除数，共17位
    uint32_t cmp_value = 0x10000;

    ccitt16 <<= 7; //低位补零，使得高位对齐，否则除法(xor)不能进行
    cmp_value <<= 7;//循环控制，余数足够小则结束循环
    while (cmp_value >= 0x10000)//确保第17位为1
    {
        if ((data & cmp_value) != 0)
        {
            data ^= ccitt16;
        }
        else
        {

        }


        ccitt16 >>= 1;//滑动除数，而被除数不动
        cmp_value >>= 1;
    }

    data &= 0xFFFF; //只保留低16位，高位清零
    return (data^0x0000); //标准中“对结果的处理”中，和0x0000异或，其实data无变化，完全可以省略。
}

int main(void)
{
    uint16_t crc=crc16_div();
    printf("crc is %x\n", crc);
}
// 输出：
// crc is 1080
