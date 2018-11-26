#include <stdio.h>

int bar(int x, int y, int z )
{
    int sum=0;
    sum = x + y + z;

    return sum;
}
int foo(int x, int y, int z)
{
    int m=11;
    int n=13;
    int f1=bar(x, y, z);
    int f2=f1+m+n;

    return f2;
}

int main(void)
{
    int i=3;
    int j=9;
    int k=7; 

    int n = foo(i, j, k);

    printf("n=%d\n", n);

    return 0;
}

