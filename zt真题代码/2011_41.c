#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char x=200;
    int a=300;
    bool flag;
    int value1, value2;
    value1=200;
    value2=300;

    if(flag && ( (value1=value2)==200)) {
        x =x +a;
    }

    printf("x=%d\n", x);
    
    return 0;
}

