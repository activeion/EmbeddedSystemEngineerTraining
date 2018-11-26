int (*serial_puts)(const char *)=(int (*)(const char *))0x60838304;
int (*sprintf)(char* buf, const char *, ...)=(int (*)(char* buf, const char *, ...))0x60866fd4;

int glob_stop_here=0;

int main(void)
{
    while(glob_stop_here);

    char buf[256];
    sprintf(buf, "hello, u-boot. glob_stop_here=%d.\n", glob_stop_here);
    serial_puts(buf);

    return 0;
}

