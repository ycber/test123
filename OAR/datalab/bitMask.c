

#include <stdio.h>
#include <stdlib.h>


int printBits(int x) {
    int i;

    printf("x ist %x \n",x);

    for (i = 31; i >= 0; i--) {

        printf("%d",((x >> i) & 1));

    }
    printf("\n");

    return 0;
}


/*
* bitMask - Generate a mask consisting of all 1's
* lowbit and highbit
* Examples: bitMask(5,3) = 0x38
* Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
* If lowbit > highbit, then mask should be all 0's
* Legal ops: ! ~ & ^ | + << >>
* Max ops: 16
* Rating: 3
*/
int bitMask(int highbit, int lowbit) {

  int x;
  int y;
  int c;


  x = 1 << 31;                           // 10000...0 bzw 0xA0000000 erzeugen
  y = x;
  x = x >> (31 - lowbit);                // durch arithmetischen Shift von höchsten bit bis lowbit alles voller Einsem

  y = y >> ((31 - highbit) - 1);         // durch arithmetischen Shift von höchsten bit bis hightbit+1 alles voller Einsen

  c = !(!(31 - highbit));                // gucken, ob highbit = 31 war
  c = c << 31; c = c >> 31;              // entsprechen 111...1 oder 000...0 erzeugen
  y = y & c;                             // y löschen, wenn highbit = 31 war

  y = ~y;                                // erzeugt Nullen bis highbit +1


return (x & y);                          // Einsen von lowbit mit Nullen von highbit kombinieren
}

int main()
{
    int sum;

   sum = bitMask(31,2);

   printf(" result ist %d\n",sum);
   printBits(sum);

printf("\n\n\n");



   return 0;
}

