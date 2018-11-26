#include <stdio.h>

int g(int x)
{
    return x + 57;
}

int f(int x)
{
    return g(x);
}

int main(void)
{ 
    return f(9) +1;
}
