int g_stop_here=1;


int main(void)
{
    char buf[500];
    int a=0x9988;
    int b=0x9988;
    int c=0x9988;
    int d=0x9988;
    int e=0x9988;
    int f=0x9988;
    while(g_stop_here);

    a = func(1);


    return 0;
}

int func(int param1)
{
    char buf[99];
    param1++;

    return param1;
}


