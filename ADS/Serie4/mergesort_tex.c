#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* This function generates an array of random integers in the range [0,9999] of length n. */
int* random_array(const int n) {
  int *x;
  int i;

  x = (int*) malloc(n * sizeof(int));

  srand(time(NULL ));

  for (i = 0; i < n; i++) {
    x[i] = rand() % 10000;
  }

  return x;
}

/* print an array. */
void print_array(const int n, const int *x, int u) {
  int i;
   printf("\n");

  for (i = 0; i < n && i < 32; i++) {
    printf("node[place] at (%d,%u) {",i+1,u);
    printf("%d};", x[i]);
  }
  if (n > 32) {
    printf("...");
  }
  printf("\n");
}

/* print an array. */
void print_array_o(const int n, const int *x, int u) {
  int i;

  printf("array: ");
  for (i = 0; i < n && i < 32; i++) {
    printf("%d ", x[i]);
  }
  if (n > 32) {
    printf("...");
  }
  printf("\n");
}
/*

\node[place] at (1,8) {1}; \node[place] at (2,8) {17};\node[place] at (3,8) {3};\node[place]at (4,8) {9};\node[place] at (5,8) {8};
\node[place]  at (6,8) {2}; \node[place] at (7,8) {13};\node[place] at (8,8) {14};\node[place]  at (9,8) {16};\node[place]  at (10,8) {4};
*/


/* Sort an array by using insertion sort algorithm */
void insertion_sort_forward(const int n, int *x) {
  int i, j, u;
  int y;
  u = 6;
  for (j = 1; j < n; j++) {
    y = x[j];
    i = j;
    while ((i > 0) && (x[i - 1] > y)) {
      x[i] = x[i - 1];
      i--;
      u++; u++;
      print_array_o(n, x, u);
    }
    x[i] = y;
    u++; u++;
    print_array_o(n, x, u);
  }

}

void mergesort(int n, int *x, int *h) {
    int *y, *z, *hy, *hz;
    int m;
    int i, j, k;
    if(n > 1) {
        m = n / 2;
        y = h; z = h + m;
        hy = x; hz = x + m;
        for(i=0; i<n; i++) {
            h[i] = x[i];
        }
        print_array_o(n, x, 1);
        print_array_o(n, h, 1);

        mergesort(m, y, hy);
        mergesort(n-m, z, hz);
        j = 0; k = 0;
        for(i=0; i<n; i++)
            if(j == m || (k+m < n && y[j] > z[k])) {
                x[i] = z[k]; k++;
                print_array_o(n, x, 1);
        }
        else {
            x[i] = y[j]; j++;
            print_array_o(n, x, 1);
        }
    }
}


int main() {
  int *x, *y, *h;
  int n;

  /* set length of the arrays */
  n = 10;

  x = (int*) malloc(10 * sizeof(int));
  h = (int*) malloc(10 * sizeof(int));
  x[0] = 1;
  x[1] = 17;
  x[2] = 3;
  x[3] = 9;
  x[4] = 8;
  x[5] = 2;
  x[6] = 13;
  x[7] = 14;
  x[8] = 16;
  x[9] = 4;

  /* copy that array to y in order to be able to compare insertion_sort_forward
   * and insertion_sort_backward later on. */
  y = (int*) malloc(n * sizeof(int));
  memcpy(y, x, n * sizeof(int));


  printf("\n\n");
  printf("Insertion sort forward:\n");

  /* sort x by using insertion_sort_forward, check if it is sorted and print it out */
  /* insertion_sort_forward(n, x);  */

  mergesort(n, x, h);


  printf("End\n\n");
  print_array_o(n, x, 1);

  return 0;
}
