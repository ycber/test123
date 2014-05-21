

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
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {

int mask;
int j;
int mask2;
int ans;
mask = 0x11;
mask = (mask << 8) | mask;
mask = (mask << 16) | mask;

j = mask & x;
j = j + (mask & (x>>1));
j = j + (mask & (x>>2));
j = j + (mask & (x>>3));
j = j + (j >> 16);

mask2 = 0xf;

ans = j & mask2;
ans = ans + ((j >> 4) & mask2);
ans = ans + ((j >> 8) & mask2);
ans = ans + ((j >> 12) & mask2);


 return ans;
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

