

#include <stdio.h>
#include <stdlib.h>


int printBits(int x) {
    int i;



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

  int a, b;
  int result;


  a = 1 << 31;
  a = a >> 31;           // alles Einsen produzieren

  result = a << lowbit;  // lowbit Nullen reinschieben
  printf("a: %d\n",result);  printBits(result);


  b = a << 1;

  printf("b nach shift 1: %d\n",b); printBits(b);

  b = b << (highbit);    // highbit + 1 Nullen reinschieben


  printf("b nach Shift ...: %d\n",b); printBits(b);
  result = result & ~b;  // lowbit und highbit Zahlen kombinieren


return result;                          // Einsen von lowbit mit Nullen von highbit kombinieren
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

sum = bitMask(31,0);

   printf(" 31, 0 result ist %d\n",sum);
   printBits(sum);

printf("\n\n\n");


   return 0;
}

