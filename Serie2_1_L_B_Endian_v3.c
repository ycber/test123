#include <stdio.h>
typedef unsigned char *pointer;


int is_little_endian() {
    pointer start;
    int a = 0001;
    start = (pointer) &a;

    if (start[0]) {
       return 1;
    }
    else {
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
