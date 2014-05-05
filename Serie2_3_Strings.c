#include <stdio.h>

#define MAX_SLENGTH 255


char *TXT = "abcd";


typedef struct s_mystring {
    unsigned char length;
    char content[MAX_SLENGTH];
} mystring;








int string2mystring(char *s, mystring *ms) {

   int cnt = 0;
   while (s[cnt] != 0) {
      (*ms).content[cnt] = s[cnt];
      cnt++;
      if ((cnt == MAX_SLENGTH + 1) && (s[cnt] != 0)) {
         (*ms).length = cnt;
         return 1;
      }
   }
   (*ms).length = cnt;
   return 0;
}



int mystring2string(mystring *ms, char *s, int size) {

   int cnt;
   int end;
   end = (*ms).length < size ? (*ms).length : size;
   for (cnt = 0; cnt < end; cnt++) {
      s[cnt] = (*ms).content[cnt];
   }
   s[cnt] = 0;
   if ((*ms).length > size ) {
      return 1;
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
      printf("Die Konvertierung des folgenden Strings in die Struktur war nicht erfolgreich: \n\"%s\"  \n", a);
   }
   else {
      printf("Die Konvertierung des folgenden Strings in die Struktur war erfolgreich: \n\"%s\"  \n", a);
   }
   printf("\n");




   if (mystring2string(&x, c, 24)) {
      printf("Bei der Konvertierung von Struktur in String musste gekuerzt werden:: \n\"%s\"  \n", c);
   }
   else {
      printf("Die Konvertierung der Struktur in String war erfolgreich: \n\"%s\"  \n", c);
   }
   printf("\n");


   if (mystring2string(&x, d, 26)) {
      printf("Bei der Konvertierung von Struktur in String musste gekuerzt werden: \n\"%s\"  \n", d);
   }
   else {
      printf("Die Konvertierung der Struktur in String war erfolgreich: \n\"%s\"  \n",d);
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
