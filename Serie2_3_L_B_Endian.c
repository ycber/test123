
typedef unsigned char *pointer;

void show_bytes(pointer start, int len) {
   int i;
   for (i = 0; i < len; i++)
      printf("0x%p\t0x%.2x\n", start+i, start[i]);
   printf("\n");
}


int main() {


   int a = 0001;
   printf("int a = 0001;\n");
   show_bytes((pointer) &a, sizeof(int));

  return 0;
}