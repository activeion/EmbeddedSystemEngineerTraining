#include <stdio.h>

int d_eax;
int d_ebx;
int d_ecx;
int d_edx;
int parse_cache()
{

    asm
        (
         "movl $2,%eax\n\t"
         "cpuid\n\t"
         "mov %eax,d_eax\n\t"
         "mov %ebx,d_ebx\n\t"
         "mov %ecx,d_ecx\n\t"
         "mov %edx,d_edx\n\t"
        );

    printf("d_eax : %x\n"
            "d_ebx : %x\n"
            "d_ecx : %x\n"
            "d_edx : %x\n",
            d_eax,d_ebx,d_ecx,d_edx);
    return 0;

}
int main()
{
    parse_cache();
    return 0;
}
