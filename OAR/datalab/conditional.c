

#include <stdio.h>
#include <stdlib.h>

/*
* conditional - same as x ? y : z
* Example: conditional(2,4,5) = 4
* Legal ops: ! ~ & ^ | + << >>
* Max ops: 16
* Rating: 3
*/
int conditional(int x, int y, int z) {

    int a, b;

    a = !x;
    a = a << 31;       // wenn x = 0  ist, bleibt es 0
    a = a >> 31;       // wenn x != 0 ist, saubere 111111...1 erzeugen
    a = a & z;         // wenn x = 0 ist, wird z nicht übernommen
                       // wenn x != 0 ist, wird z übernommen

    b = (!(!x));
    b = b << 31;       // wenn x = 0  ist, wird eine 1111...1 erzeugt
    b = b >> 31;       // wenn x != 0 ist, wird eine 0 erzeugt
    b = b & y;         // y je nach x übernehmen

  return (a | b);      // entweder x oder y zurückgeben
}

int main()
{
    int sum;

   sum = conditional(0,3,7);

   printf(" ist %d\n",sum);

   sum = conditional(55,3,7);

   printf(" ist %d\n",sum);

   return 0;
}

