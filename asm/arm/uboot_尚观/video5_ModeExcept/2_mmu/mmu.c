int (*serial_puts)(const char *)=(int (*)(const char *))0x60838304;
int (*sprintf)(char* buf, const char *, ...)=(int (*)(char* buf, const char *, ...))0x60866fd4;
int g_stop_here=0;

void init_ttb(unsigned long *ttb);

int main()
{
    while(g_stop_here);

    //0x32300000 -> 0x52300000;
    //unsigned long *pp = 0x52300000;
    
    //0x32300000 -> 0x62300000;
    unsigned long *pp = 0x62300000;
    *pp = 0x22222222;

    {
        //printf("*pv is %x\n", *pp);
        char buf[256];
        sprintf(buf, "pp=%#x, *pp = %#x\n", pp, *pp);
        serial_puts(buf);
    }

    //step 1: set mmu table
    unsigned long ttb = 0x70000000;
    init_ttb(ttb);

    //step 2: enable mmu table
    unsigned long mmu = 0;
    mmu = 1 | (1 << 3) | (1 << 8);
    __asm__ __volatile__(//开启mmu必须用汇编实现
            "mov r0, #3\n"
            "mcr p15, 0, r0, c3, c0, 0\n" //manager
            "mcr p15, 0, %0, c2, c0, 0\n" //ttb address
            "mcr p15, 0, %1, c1, c0, 0\n" //enable mmu
            :
            : "r" (ttb), "r" (mmu)
            );

    unsigned long *pv = 0x32300000;

    {
        //printf("*pv is %x\n", *pv);
        char buf[256];
        sprintf(buf, "pv=%#x, *pv = %#x\n", pv, *pv);//访问pv所指向的内存
        serial_puts(buf);
    }
}

void init_ttb(unsigned long *ttb)
{
    unsigned long va = 0;
    unsigned long pa = 0;
    //0x00000000 ~0x14000000 -> 0x00000000 ~0x14000000 
    for(va=0x00000000; va<0x14000000; va+=0x100000){
        pa = va;
        ttb[va >> 20] = pa | 2;
    }

    //0x40000000 ~0x80000000 -> 0x40000000 ~0x80000000 
    //for(va=0x40000000; va<0x80000000; va+=0x100000){
    //...
    //0x40000000 ~0xa0000000 -> 0x40000000 ~0xa0000000 
    for(va=0x40000000; va<0xa0000000; va+=0x100000){
        pa = va;
        ttb[va >> 20] = pa | 2;
    }

    //0x30000000 ~0x40000000 -> 0x50000000 ~0x60000000 
    //0x30000000 ~0x40000000 -> 0x60000000 ~0x70000000 
    for(va=0x30000000; va<0x40000000; va+=0x100000){
        //pa = va + 0x20000000;
        pa = va + 0x30000000;
        ttb[va >> 20] = pa | 2;

        {
            //printf("pv=%#x, *pv is %x\n", pv, *pv);
            char buf[256];
            sprintf(buf, "%#x->%#x ttb[%#x]=%#x\n", va, pa, va>>20, pa|2);//访问pv所指向的内存
            serial_puts(buf);
        }
    }
}

/********
 * Q1: L65 0xa -> 0x8可否？
 * Q2: pa | 2的目的？ -> wiz search  zqixiao_09
 * Q3: L74 0x3 -> 0x2 可否？
 */
