

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

  int a , a2, b;

  a = ~highbit;

  b = ~lowbit + 1;

  a2 = 31 + a;

  x = 1 << 31;
  y = x;
  x = x >> (31 + b);

  y = y >> a2;

  c = !(!(a2 + 1));
  c = c << 31; c = c >> 31;
  y = y & c;

  y = ~y;


return (x & y);                          // Einsen von lowbit mit Nullen von highbit kombinieren
}

int main()
{
    int sum;

   sum = bitMask(31,2);

   printf(" 31, 2 result ist %d\n",sum);
   printBits(sum);

   sum = bitMask(5,3);

   printf(" 5, 3 result ist %d\n",sum);
   printBits(sum);

printf("\n\n\n");



   return 0;
}

