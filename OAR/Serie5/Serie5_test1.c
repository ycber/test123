#include <stdio.h>
#include <stdlib.h>

int dummy(int y, int* z) {
  asm (
    "movl 0x8(%ebp), %ecx\n"
    "movl 0xc(%ebp), %eax\n"
    "movl (%eax), %edx\n"
    "xorl %eax, %eax\n"
    "addl %edx, %eax\n"
    "imull %ecx, %eax\n"
    "andl %eax, %edx\n"
    "leal (, %eax, 4), %eax\n"
     );
}

int main() {
  int a = 10;
  int temp = dummy(2, &a);
  printf("Rueckgabe von dummy(2, &a) fuer a == 10: %d (Inhalt von eax)\n",temp);
  printf("Neuer Wert von a: %d\n", a);
  return 0;
}
