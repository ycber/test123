#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* gibt einen 32 bit vektor aus */
int print_bit_array(int * x) {
   int i;

   for (i = 31; i >= 0; i--) {
      printf("%d", x[i]);
   }
   printf("\n");

   return 0;
}

/* erzeugt ein array mit 32 zufälligen Werten */
int make_bit_array(int * x) {
   int i;

   for (i = 0; i < 32; i++) {
      *(x+i) = rand() % 2;                /* Erzeugt ein Array mit zufälligen Werten 1 oder 0 */
   }

   return 0;
}



/* erzeugt einen Integer aus einem array von bits */
int create_int(int bits[]) {
  int i;
  int result;

  result = 0;
  for (i = 31; i >= 0; i--) {
    result = result << 1;        /* im ersten Durchlauf wird nur 0 verschoben, danach wird immer die letzte Stelle freigemacht  */
    result = result | bits[i];   /* die aktuelle Stelle mit oder verknüfen, um sie in den Vektor zu schreiben                   */
  }

  return result;
}


int main() {
   int int_vektor;
   int x[32];

   srand(time(NULL));  /* rand ein wenig zufälliger machen */

   make_bit_array(x);
   int_vektor = create_int(x);
   printf("Bit-Vektor: "); print_bit_array(x);
   printf("Integer-Vektor: %d", int_vektor);
   return 0;
}
