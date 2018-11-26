#include <stdio.h>

#define SQUARE(a) ((a)*(a))

int main(void)
{

    int i, result;
    i=1;

    do {
        result = SQUARE(i++);
        //result = SQUARE(i); i++;
        printf("result=%d\n", result);
    }while(i<101);

    return 0;
}
