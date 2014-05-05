
typedef unsigned char *pointer;

void show_bytes(pointer start, int len) {
   int i;
   for (i = 0; i < len; i++)
      printf("0x%p\t0x%.2x\n", start+i, start[i]);
   printf("\n");
}

void decide_endian(pointer start) {
   if (start[0]) {
      printf("Little Endian");
   }
   else {
      printf("Big Endian");
   }


}


int main() {


   int a = 0001;
   printf("int a = 0001;\n");
   show_bytes((pointer) &a, sizeof(int));
   decide_endian((pointer) &a);

  return 0;
}
