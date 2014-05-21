

#include <stdio.h>
#include <stdlib.h>


int isGreater(int x, int y) {

   int a; int b; int e; int f;
   int sub; int sub2; int result;
   int mask;

   mask = (1 << 31) | 1;

   a = y >> 1;              // teilt beide zahlen jeweils durch 2
   b = x >> 1;
   b = (~b) + 1;
   sub = a + b;             // rechnet y/2 - x/2 (jeweils abgerundet)

   result = sub >> 31;
   result = result & 1;     // nur das Vorzeichenbit in das Ergebnis schreiben

   e = y & mask;            // jeweils LSB von x und y holen     (Vorzeichenbehaftet)
   f = x & mask;
   f = (~f) +1;
   sub2 = e + f;            // LSB von x von LSB  von y abziehen
   sub2 = sub2 >> 31;
   sub2 = sub2 & 1;         // nur das Vorzeichenbit behalten
   sub2 = sub2 & !sub;      // nur wenn x/2 = y/2 war, sind die LSBs interessant

   result = result | sub2;  // Vorzeichenbits verodern
   return result;
}

int main()
{
    int sum;

   sum = isGreater(3,7);

   printf("3 groesser 7 ist %d\n",sum);

   sum = isGreater(8,7);

   printf("8 groesser 7 ist %d\n",sum);

   sum = isGreater(8,8);

   printf("8 groesser 8 ist %d\n",sum);

   sum = isGreater(-1,0);

   printf("-1 groesser 0 ist %d\n",sum);

   sum = isGreater(-1,-3);

   printf("-1 groesser -3 ist %d\n",sum);


   return 0;
}

