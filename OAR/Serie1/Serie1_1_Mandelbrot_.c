/* Organisation und Architektur von Rechnern -- Sommersemester 2014
 *   Blatt 1, Aufgabe 1
 *   Timm-Oliver Stooß  -   stu116914@mail.uni-kiel.de
 */

#include <stdio.h>
#include <stdlib.h>



                                         /* Datenstruktur für komplexe Zahlen */
typedef struct s_complex {
    double re;
    double im;
} complex;

                                         /* Berechnet das nächste Folgenglied */
                                         /* und überschreibt das Übergebene mit dem Nächsten */
void compute_next(complex *z, complex *c) {

    double re, im;

    re = z->re * z->re - z->im * z->im * z->im + c->re;
    im = 2 * z->re * z->im + c->im;
    z->re = re;
    z->im = im;

}
                                         /* Berechnet, ob die Folge beschränkt ist  */
                                         /* Rückgabe 1 bei vermutlich beschränkt    */
                                         /* Rückgabe 0 sonst                        */
int bounded_sequence(complex *c) {

    int i; double condition;
    complex z;
    z.re = 0;
    z.im = 0;

    for (i = 0; i < 301; i++) {
        compute_next(&z, c);
        condition = z.re * z.re + z.im * z.im;
        if (condition > 4) {
            return 0;
        }
    }
    return 1;
}

                                         /* Zeichnet eine Mandelbrot-Menge                        */
                                         /* Standmässig Weite 80, Höhe 30                         */
                                         /* Es kann Weite und Höhe als Parameter übergeben werden */
int main(int argn, char *argv[]) {

    int i, j;
    int w, h;
    complex c;
                                      /* Breite und Höhe der Ausgabe setzen             */
    if (argn == 1) {
        w = 80;                       /* default, wenn keine Parameter übergeben wurden */
        h = 30;
    }
    else {
        if (argn == 3) {              /* entspechend den Paramtern setzen, wenn 2 Parameter übergeben wurden */
            w = atoi(argv[1]);
            h = atoi(argv[2]);
        }
        else {                        /* wenn eine falsche Anzahl von Parametern übergeben wurde */
            printf("Falsche Anzahl von Parametern!\n");
            return -1;
        }
    }
    printf("Mandelbrot-Menge mit Höhe = %d und Breite = %d\n",w,h);
    printf("\n");
                                      /* Schleife, um die Mandebrot-Menge zu zeichnen */
    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            c.re = (double) 3 * j / w - 2;
            c.im = (double) 2 * i / h - 1;
            if (bounded_sequence(&c)) {        /* beschränktes Folgenglied gibt ein '+' */
                    printf("+");
            }
            else {                             /* sonst ein Leerzeichen                 */
                    printf(" ");
            }

        }
    }
    printf("\n");

    return 0;
}









