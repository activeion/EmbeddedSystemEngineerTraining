#include <stdio.h>
#include <string.h>

int main()
{
    int x = 2;
    char* str = "abcd";
    int y = (x-strlen(str))/3;
    //编译器有可能会优化为右移一位。要避免这个优化
    printf("y=%d\n", y);
    
    return 0;
}

