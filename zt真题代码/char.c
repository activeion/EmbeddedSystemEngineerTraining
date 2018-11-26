//啊0
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    signed char a = 127;
    a+=1;
    printf("%d\n", a);

    a = 0b10000000;
    printf("a=%d\n", a);

    int16_t b = 65535;
    printf("b=%d\n", b);
    b+=1;
    printf("b=%d\n", b);

    int16_t c =32767;
    c+=1;
    printf("%d\n", c);

    // -129 
    // = 1000 0000 0000 0000 0000 0000 1000 0001(原码32bit) 
    // = 1111 1111 1111 1111 1111 1111 0111 1111(补码) 
    // = 0111 1111(截断) 
    // = +127
    a = -129; 
    printf("%d\n", a);

    return 0;
}

