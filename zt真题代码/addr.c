#include <stdio.h>
#include <stdlib.h>

int global_init_a=1; //全局的，初始化的变量 -> 数据段
int global_uninit_a; //全局的，没有初始化的变量 -> 数据段
static int static_global_init_a=1; //全局的，静态的，初始化的变量 -> 数据段
static int static_global_uninit_a; //全局的，静态的，未初始化的变量 -> 数据段
const int const_global_a=1; //全局的，常量 -> 代码段

int global_init_b=1; //全局的，初始化的变量 -> 数据段
int global_uninit_b; //全局的，没有初始化的变量 -> 数据段
static int static_global_init_b=1; //全局的，静态的，初始化的变量 -> 数据段
static int static_global_uninit_b; //全局的，静态的，未初始化的变量 -> 数据段
const int const_global_b=1; //全局的，常量 -> 代码段

int main()
{
    int local_init_a=1; //局部，初始化的 -> 栈
    int local_uninit_a; //局部，未初始化的 -> 栈
    static int static_local_init_a=1; //局部，静态，初始化 -> 数据段
    static int static_local_uninit_a; //局部，静态，未初始化 -> 数据段
    const int const_local_a=1; //局部的，常量 -> 栈

    int local_init_b=1; //局部，初始化的 -> 栈
    int local_uninit_b; //局部，未初始化的 -> 栈
    static int static_local_init_b=1; //局部，静态，初始化 -> 数据段
    static int static_local_uninit_b; //局部，静态，未初始化 -> 数据段
    const int const_local_b=1; //局部，常量 -> 栈

    int *malloc_p_a;
    malloc_p_a=malloc(sizeof(int)); //通过malloc分配得到的，局部 -> 堆

    printf("&global_init_a=%p, global_init_a=%d\n", &global_init_a,global_init_a);
    printf("&global_uninit_a=%p, global_uninit_a=%d\n", &global_uninit_a,global_uninit_a);
    printf("&static_global_init_a=%p, static_global_init_a=%d\n", &static_global_init_a,static_global_init_a);
    printf("&static_global_uninit_a=%p, static_global_uninit_a=%d\n", &static_global_uninit_a,static_global_uninit_a);
    printf("&const_global_a=%p, const_global_a=%d\n", &const_global_a,const_global_a);

    printf("&global_init_b=%p, global_init_b=%d\n", &global_init_b,global_init_b);
    printf("&global_uninit_b=%p, global_uninit_b=%d\n", &global_uninit_b,global_uninit_b);
    printf("&static_global_init_b=%p, static_global_init_b=%d\n", &static_global_init_b,static_global_init_b);
    printf("&static_global_uninit_b=%p, static_global_uninit_b=%d\n", &static_global_uninit_b,static_global_uninit_b);
    printf("&const_global_b=%p, const_global_b=%d\n", &const_global_b,const_global_b);

    printf("&local_init_a=%p, local_init_a=%d\n", &local_init_a,local_init_a);
    printf("&local_uninit_a=%p, local_uninit_a=%d\n", &local_uninit_a,local_uninit_a);
    printf("&static_local_init_a=%p, static_local_init_a=%d\n", &static_local_init_a,static_local_init_a);
    printf("&static_local_uninit_a=%p, static_local_uninit_a=%d\n", &static_local_uninit_a,static_local_uninit_a);
    printf("&const_local_a=%p, const_local_a=%d\n", &const_local_a,const_local_a);

    printf("&local_init_b=%p, local_init_b=%d\n", &local_init_b,local_init_b);
    printf("&local_uninit_b=%p, local_uninit_b=%d\n", &local_uninit_b,local_uninit_b);
    printf("&static_local_init_b=%p, static_local_init_b=%d\n", &static_local_init_b,static_local_init_b);
    printf("&static_local_uninit_b=%p, static_local_uninit_b=%d\n", &static_local_uninit_b,static_local_uninit_b);
    printf("&const_local_b=%p, const_local_b=%d\n", &const_local_b,const_local_b);

    printf("malloc_p_a=%p, *malloc_p_a=%d\n",malloc_p_a,*malloc_p_a);

    while(1);
    return 0;
}
