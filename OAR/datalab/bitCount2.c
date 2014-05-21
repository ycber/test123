

#include <stdio.h>
#include <stdlib.h>

/*
* bitCount - returns count of number of 1's in word
* Examples: bitCount(5) = 2, bitCount(7) = 3
* Legal ops: ! ~ & ^ | + << >>
* Max ops: 40
* Rating: 4
*/
int bitCount(int x) {                  // funktioniert nur mit 4 bits
    int a; int b;
    int res1; int res2;
    int result;


    b = x & 1;
    a = (x & 2) >> 1;
    res1 = a & b;
    res2 = a | b;
    result = res1 + res2;

    x = x >> 2;

    a = (x & 2) >> 1;
    b = x & 1;
    res1 = a & b;
    res2 = a | b;
    result = result + res1 + res2;

    return result;
}

int main()
{
   unsigned int n; int sum;
   printf("Bitte geben Sie eine Zahl ein : ");
   scanf("%d",&n);
   sum = bitCount(n);
   printf("Die Anzahl der Bits in %d",n);
   printf(" ist %d\n",sum);
   return 0;
}

