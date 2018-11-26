#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gb = 0x50505050;
char *gb_string = "/bin/sh";

unsigned int get_bp(int val)
{
  printf("ebp_caller=%#x.n", *(&val-2));
  printf("ret_caller=%#x.n", *(&val-1));
  __asm__("movl %ebp,%eax");
}

unsigned int get_ip(void)
{
  __asm__("lea main,%eax");
}

int main()
{
  int stk = 0x51515151;
  char *stk_string = "/bin/sh";
  char stk_buf[32];
  char *heap = NULL;

  heap = malloc(32);

  printf("stack: ebp_cur=%#x, firstval:%#x, buf:%#x.n", *((int*)get_bp(1)), &stk, stk_buf);
  printf("heap: alloc in %#x(stk_ptr:%#x).n", heap, &heap);
  printf("global data: gb:%#x.n", &gb);
  printf("rdonly data: stk_string_prt->%#x(stkaddr:%#x), gb_string_prt->%#x(gbaddr:%#x).n", stk_string, &stk_string, gb_string, &gb_string);
  printf("code text: main:%#x.n", get_ip());

  return 0;
}
