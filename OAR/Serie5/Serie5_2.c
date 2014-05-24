
#include <stdio.h>
#include <stdlib.h>

int decode1(int x, int y, int z) {
  asm (
     "movl 16(%ebp), %eax\n"
     "movl 12(%ebp), %edx\n"
     "subl %eax, %edx\n"
     "movl %edx, %eax\n"
     "imull 8(%ebp), %edx\n"
     "sall $31, %eax\n"
     "sarl $31, %eax\n"
     "xorl %edx, %eax\n"
  );
}

int decode2(int x, int y, int z) {

  int tmp;
  int lsb;

  tmp = x * (y - z);
  lsb = (y - z) << 31;
  lsb = lsb >> 31;

  return (tmp ^ lsb);
}

int decode3(int x, int y, int z) {

  int tmp;

  tmp = y -z;
  if ((tmp/2)*2 == tmp) {
     return (x * tmp);
  }
  else {
     return ~(x * tmp);
  }
}

int main()
{

   printf("Ergebnis Assembler bei 1, 6, 3: %d\n",decode1(1,6,3));
   printf("\n");
   printf("Ergebnis decode2 in C Assembler-nah bei 1, 6, 3: %d\n",decode2(1,6,3));
   printf("\n");
   printf("Ergebnis in C mit Integer ausnutzen bei 1, 6, 3: %d\n",decode3(1,6,3));

   printf("\n");
   printf("\n");

   printf("Ergebnis Assembler bei 7, 9, 4: %d\n",decode1(7,9,4));
   printf("\n");
   printf("Ergebnis decode2 in C Assembler-nah bei 7, 9, 4: %d\n",decode2(7,9,4));
   printf("\n");
   printf("Ergebnis in C mit Integer ausnutzen bei 7, 9, 4: %d\n",decode3(7,9,4));

   printf("\n");
   printf("\n");

   printf("Ergebnis Assembler bei 2, 7, 9: %d\n",decode1(2,7,9));
   printf("\n");
   printf("Ergebnis decode2 in C Assembler-nah bei 2, 7, 9: %d\n",decode2(2,7,9));
   printf("\n");
   printf("Ergebnis in C mit Integer ausnutzen bei 2, 7, 9: %d\n",decode3(2,7,9));


   return 0;
}
