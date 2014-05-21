
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


int isGreater(int x, int y) {

   int a, b, result;

   a = x & (1 << 31);
   b = y & (1 << 31);

   printBits(a);
   printBits(b);

   result = a & !b;


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

