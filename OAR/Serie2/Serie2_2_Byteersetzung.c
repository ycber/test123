/* Organisation und Architektur von Rechnern -- Sommersemester 2014
 *   Blatt 2, Aufgabe 2
 *   Timm-Oliver Stooﬂ  -   stu116914@mail.uni-kiel.de
 */

#include <stdio.h>
#include <stdlib.h>


unsigned int put_byte(unsigned int x, unsigned char b, int i) {
   if ((i<0) || (i>3)) {
      printf("ungueltiger Wert fuer i = %d\n", i);
      return 0;
   }
   unsigned int bb;
   unsigned int a;
   bb = b;                  /* wandle char in unsigned int um                                                */
   a = 0xFF;                /* Maske erstellen                                                               */
   a = a << i*8;            /* an die richtige Stelle shiften                                                */
   a = ~a;                  /* Bits umdrehen                                                                 */
   bb = bb << i*8;          /* das neue Byte an die richtige Stelle bringen                                  */
   bb = (x&a)|bb;           /* Eingabe mit Maske verkn¸pfen, und anschlieﬂend das neue Byte reinschreiben    */
   return bb;
}




int main() {

  printf("Ausgabe von zu 0x12345678, 0xab, 2 ist: %x \n", put_byte(0x12345678, 0xab, 2));
  printf("Ausgabe von zu 0x12345678, 0xab, 0 ist: %x \n", put_byte(0x12345678, 0xab, 0));
  printf("Ausgabe von zu 0x11111111, 0xab, 3 ist: %x \n", put_byte(0x11111111, 0xab, 3));


  return 0;
}


/*

put_byte(0x12345678, 0xab, 2)  -->  0x12ab5678
put_byte(0x12345678, 0xab, 0)  -->  0x123456ab

*/
