/* Organisation und Architektur von Rechnern -- Sommersemester 2014
 *   Blatt 1, Aufgabe 2
 *   Timm-Oliver Stooﬂ  -   stu116914@mail.uni-kiel.de
 */
#include <stdio.h>
#include <stdlib.h>


#define M  3
#define N  4

                                     /* feste Matrix initialisieren */
void matrix_init_fix(int a[M][N]) {

    int i, j;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = rand() % 10;      /* jedes Element zuf‰llig aus {0, ..., 9} belegen */
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

}

                                          /* feste Matrix aufsummieren */
int matrix_sum_fix(int a[M][N]) {

    int i, j, sum;
    sum = 0;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

                                         /* Variable Matrix initialisieren */
int **matrix_init_var(int m, int n) {

    int i, j;
    int **var_matrix;                                /* Die neue Matrix */
    var_matrix = (int**) malloc(n * sizeof(int*));   /* Speicher f¸r die Zeiger auf die einzelnen Zeilen */


    for (i = 0; i < m; i++) {
            *(var_matrix+i) = (int*) malloc(n * sizeof(int*));    /* Speicher f¸r die komplette Zeile reservieren */
        for (j = 0; j < n; j++) {
            *(*(var_matrix+i)+j) = rand() % 10;        /* Zufallszahlen an jede Position der Matrix schreiben */
            printf("%d ", *(*(var_matrix+i)+j));

        }
        printf("\n");
    }
    return var_matrix;
}

                                      /* Variable Matrix aufsummieren */
int matrix_sum_var(int **a, int m, int n) {
    int i, j;

    int sum;                          /* Variabel zum Aufsummieren */
    sum = 0;

    for (i = 0; i < m; i++) {
       for (j = 0; j < n; j++) {
            sum += *(*(a+i)+j);       /* Aufsummieren der einzelnen Zellen */
       }
    }
    return sum;
}



                                      /* Speicherplatz der variablen Matrix freigeben */
void matrix_free(int **a, int m) {
    int i;
    for (i=0; i < m; i++){
        free(*a+i);                   /* eine Zeile mit Zeigern freigeben */
    }
    free(a);                          /* Das array mit den Zeigern auf die Zeilen freigeben */
}




int main() {
    int a1[M][N];
    int **a2;
    int sum;

    matrix_init_fix(a1);
    sum = matrix_sum_fix(a1);
    printf("\nfixed sum = %d\n\n", sum);

    a2 = matrix_init_var(M, N);
    sum = matrix_sum_var(a2, M, N);
    printf("\nvariable sum = %d\n\n", sum);
    matrix_free(a2, M);

    return 0;
}
