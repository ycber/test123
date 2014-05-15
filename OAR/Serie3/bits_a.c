#include <stdio.h>
#include <stdlib.h>




/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    int result;
    int y = 0x7F;
    int z = 0xFF;
    y = y << 8;
    y = y | z;
    y = y << 8;
    y = y | z;
    y = y << 8;
    y = y | z;

    printf("y: %x \n", y);

    result = y >> (31 - (highbit - 2));
    printf("r: %x \n", result);
    result = result << lowbit;
    printf("r: %x \n", result);

    printf("\n");


  return result;
}


/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~(~x | ~y);
}


/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {

    int tmp;

    tmp = !(!(x));

    return ((tmp & y) | (~tmp & z));
}

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
    int x = 0x55;
    x = (x << 8) | x;
  return ((x << 16) | x);
}

/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    int result = 0;
    n = n << 3;
    result = (x >> n) & 0xFF;
    return result;
}


/*
* isGreater - if x > y then return 1, else return 0
* Example: isGreater(4,5) = 0, isGreater(5,4) = 1
* Legal ops: ! ~ & ^ | + << >>
* Max ops: 24
* Rating: 3
*/
int isGreater(int x, int y) {
    int a;
    y = ~y;                 // Zweierkomplement -1
    a = x + y;              // x - (y+1) rechnen
    a = a >> 31;            // Vorzeichenbit an LSB schieben
    a = a & 1;              // Vorzeichenbit maskieren
  return a;
}

int tmax(void) {
  return ~(1 << 31) ;
}


int main() {


   printf("bitOr(5,5): %x \n", bitOr(5,5));
   printf("bitOr(0,5): %x \n", bitOr(0,5));
   printf("bitOr(2,5): %x \n", bitOr(2,5));

   printf("\n");

   printf("evenBits(): %x \n", evenBits());

printf("\n");

   printf("bitMask(31,3): %x \n", bitMask(31,0));

printf("\n");
/*
   printf("conditional(2,4,6): %x \n", conditional(2,4,5));
   printf("conditional(0,4,6): %x \n", conditional(0,4,6));

   printf("getByte(0x1A1B1C1D,0): %x \n", getByte(0x1A1B1C1D,0));
*/

   printf("isGreater(4,5): %d \n", isGreater(4,5));
   printf("isGreater(5,5): %d \n", isGreater(5,5));
   printf("isGreater(5,4): %d \n", isGreater(5,4));
   printf("isGreater(8,4): %d \n", isGreater(8,4));

printf("\n");

   printf("tmax: %d \n", tmax());

   return 0;
}

