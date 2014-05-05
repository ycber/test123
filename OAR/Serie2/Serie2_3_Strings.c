/* Organisation und Architektur von Rechnern -- Sommersemester 2014
 *   Blatt 2, Aufgabe 3
 *   Timm-Oliver Stooﬂ  -   stu116914@mail.uni-kiel.de
 */


#include <stdio.h>

#define MAX_SLENGTH 255

typedef struct s_mystring {
    unsigned char length;
    char content[MAX_SLENGTH];
} mystring;

                                                                   /* schreibt einen String in die Struktur mystring */
int string2mystring(char *s, mystring *ms) {

   int cnt = 0;
   while (s[cnt] != 0) {                                     /* solange kein Nullstring kommt */
      (*ms).content[cnt] = s[cnt];                           /* in die Struktur schreiben     */
      cnt++;
      if ((cnt == MAX_SLENGTH) && (s[cnt] != 0)) {           /* Wenn maximale L‰nge erreicht und der String nicht zu Ende ist */
         (*ms).length = MAX_SLENGTH;                         /* L‰nge in der Struktur auf maximale L‰nger setzen              */
         return 1;                                           /* und mit 1 Fehler melden                                       */
      }
   }
   (*ms).length = cnt;                                       /* Struktur L‰nge angeben */
   return 0;
}

                                                                 /* beschreibt einen String aus der Struktur mystring */
int mystring2string(mystring *ms, char *s, int size) {

   int cnt;
   int end;
   end = (*ms).length < size ? (*ms).length : size;          /* der String kann maximal die L‰nge size oder die L‰nge aus der Struktur haben */
   for (cnt = 0; cnt < end; cnt++) {
      s[cnt] = (*ms).content[cnt];                           /* in den String schreiben */
   }
   s[cnt] = 0;
   if ((*ms).length > size ) {                               /* wenn die L‰nger der Struktur l‰nger als die maximal L‰nge des Strings ist    */
      return 1;                                              /* Fehler ausgeben                                                              */
   }
   return 0;
}


int main() {

   char a[] = "abcdefghijklmnopqrstuvwxyz";
   char c[] = "                        ";
   char d[] = "                          ";
   char b[] = "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";

   mystring x;
   mystring y;


   if (string2mystring(a,&x)) {
      printf("Die Konvertierung des folgenden Strings in die Struktur war nicht erfolgreich: \n\"%s\"  \n\n", a);
   }
   else {
      printf("Die Konvertierung des folgenden Strings in die Struktur war erfolgreich: \n\"%s\"  \n\n", a);
   }
   printf("\n");




   if (mystring2string(&x, c, 24)) {
      printf("Bei der Konvertierung von Struktur in String musste gekuerzt werden: \n\"%s\"  \n\n", c);
   }
   else {
      printf("Die Konvertierung der Struktur in String war erfolgreich: \n\"%s\"  \n\n", c);
   }
   printf("\n");


   if (mystring2string(&x, d, 26)) {
      printf("Bei der Konvertierung von Struktur in String musste gekuerzt werden: \n\"%s\"  \n\n", d);
   }
   else {
      printf("Die Konvertierung der Struktur in String war erfolgreich: \n\"%s\"  \n\n",d);
   }
   printf("\n");

   if (string2mystring(b,&y)) {
       printf("Die Konvertierung des folgenden Strings in die Struktur war nicht erfolgreich: \n\"%s\"  \n", b);
   }
   else {
      printf("Die Konvertierung des folgenden Strings in die Struktur war erfolgreich: \n\"%s\"  \n", b);
   }
   printf("\n");



   return 0;
}
