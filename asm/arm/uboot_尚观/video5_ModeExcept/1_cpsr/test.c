int (*serial_puts)(const char *)=(int (*)(const char *))0x60838304;
int (*sprintf)(char* buf, const char *, ...)=(int (*)(char* buf, const char *, ...))0x60866fd4;

int glob_stop_here=0;

int main(void)
{
    while(glob_stop_here);

    unsigned long v_cpsr;
    __asm__ __volatile__ (
            "mrs %0, cpsr \n":"=r"(v_cpsr)
    );

    char buf[256];
    sprintf(buf, "mode = %#x\n", v_cpsr & 0x1f);
    serial_puts(buf);

    return 0;
}
