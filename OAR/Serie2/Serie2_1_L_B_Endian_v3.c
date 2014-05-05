/* Organisation und Architektur von Rechnern -- Sommersemester 2014
 *   Blatt 2, Aufgabe 1
 *   Timm-Oliver Stooß  -   stu116914@mail.uni-kiel.de
 */

 #include <stdio.h>

typedef unsigned char *pointer;

/* analog zur Byte-Anzeige in der Vorlesung wird absichtlich ein Zeiger auf einen Interger   *
 * auf einen Char-Zeige gecastet                                                             *
 * dadurch wird nur das letzte bzw. erste Byte des Integers ausgewertet                      */

int is_little_endian() {
    pointer start;
    int a = 0001;
    start = (pointer) &a;

    if (start[0]) {               /* wenn der Zeiger auf eine 1 zeigt, ist es little endian */
       return 1;
    }
    else {                       /* sonst Big Endian */
       return 0;
    }
}


int main() {

   if (is_little_endian()) {
       printf("Architektur ist little Endian\n");
   }
   else {
       printf("Architektur ist big Endian\n");
   }


  return 0;
}
