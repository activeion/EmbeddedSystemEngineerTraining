#include <stdio.h>

int main(void)
{
    float f=2.2f; // (gdb) x/x &f
    double d = (double)f;//(gdb) x/2x &d
    printf("size of float = %d\n", sizeof f);
    printf("size of double = %d\n\n", sizeof d);
    printf("2.2f=%6.15f\n", f);
    printf("2.2f=%6.15f\n\n", d);

    f=2.25f;
    d=(double)f;
    printf("2.25f=%6.15f\n", f);
    printf("2.25f=%6.15f\n\n", d);

    f = 2.25f - 2.2f;
    d=(double)f;
    printf("2.25f-2.2f=%6.15f\n", f);
    printf("2.25f-2.2f=%6.15f\n\n", d);

    return 0;
}
