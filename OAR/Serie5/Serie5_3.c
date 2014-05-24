
#include <stdio.h>
#include <stdlib.h>

int assemble(int a, int b) {
  asm (
     "xorl  %eax, %eax\n"                          // Ergebnis erstmal auf 0 setzen
     "movl  8(%ebp), %ecx\n"                       // a laden
     "leal  (%ecx, %ecx, 2),%ecx\n"                // a*3 rechnen
     "movl  12(%ebp), %edx\n"                      // b laden
     "imull %edx, %edx\n"                          // b*b rechnen
     "subl  %edx, %ecx\n"                          // a*3 - b*b rechnen
     "movl  $15, %edx\n"                           // 15 laden
     "subl  %ecx, %edx\n"                          // 15 - (a*3 - b*b) rechnen
     "jle    .g\n"                                 // wenn Ergebnis negativ oder 0 war, springen
     "incl  %eax\n"                                // das Ergebnis erhöhen, da (a*3 - b*b) < 15
     ".g:\n"
  );
}

int main()
{


   printf("Ergebnis assemble mit 2, 4: %d\n",assemble(2,4));
   printf("\n");
   printf("Ergebnis assemble mit 8, 3: %d\n",assemble(8,3));
   printf("\n");
   printf("Ergebnis assemble mit 3, 5: %d\n",assemble(3,5));
   printf("\n");
   printf("Ergebnis assemble mit 5, 0: %d\n",assemble(5,0));
   printf("\n");
   printf("Ergebnis assemble mit 5, -1: %d\n",assemble(5,-1));


   return 0;
}
