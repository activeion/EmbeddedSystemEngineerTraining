#include <stdio.h>
#include <inttypes.h>

/****
 * “砍头”行动
 */
uint16_t crc16_div_2()
{
    uint16_t data = 0x88;//注意：data为16位无符号数类型
    uint16_t ccitt16 = 0x1021; //注意：先“砍头”，去掉了msb=1，共16位

    data <<= 8;//ccitt16一共9位，我们将data左移9-1=8位
    //注意不能将if-else语句中的"data<<1;"提出来，
    //放在if语句的前头，因为这会影响data&8000这个条件的判断
    for (int i=0; i<8; i++) {
        if (data & 0x8000) { // if MSB of data is 1
            data <<= 1;  //与ccitt16被“砍头”相对应，msb=1先去掉
            data ^= ccitt16;//剩下的与ccitt16异或
        } else {
            data <<= 1;//删除这个msb=0
        }
    }
    return data;
}
int main(void)
{
    uint16_t crc=crc16_div_2();
    printf("crc is %x\n", crc);
}
// 输出：
// crc is 1080
