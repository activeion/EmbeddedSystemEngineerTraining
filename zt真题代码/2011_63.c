#include <stdio.h>

int main(void)
{
    char iArr[]={0,1,2,3,4,5,6,7,8,9};
    short tVal;
    short *pVal = NULL;
    pVal = (short*)(iArr+2);
    tVal= *pVal;
    printf("tVal=%#x\n", tVal);
}
