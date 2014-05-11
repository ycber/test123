#include <stdio.h>
/*
 * Include this header-file, if you like to use the 'pow' function.
 * Don't forget to link against the math library in that case by adding
 *
 *  -lm
 *
 * to the compiler call.
 */
#include <math.h>

int sgn(double x) {

    if (x > 0) {
        return 1;
    }
    else {
        if (x < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }
}

/* Berechnet den Wert der Sparkassenformel für:      *
 * Startkapital a , Einzahlung b,                    *
 * Jahreszahl m und Zinssatz q                       */
double compute_value_at_gamma(double a, double b, int m, double q) {

    double x;

    x = (b * (pow((1 + q), (m + 1)) - 1) - q * a);

    return x;

}


/*
 * Compute the value of 'q' with the input parameters a,b,m from the
 * formula in the exercise.
 * 'eps' is the stopping accuracy, 'alpha' and 'beta' are the boundaryvalues
 * of the current interval.
 */
double compute_q(double a, double b, int m, double eps, double alpha,
    double beta) {

    double gamma;

    gamma = (beta + alpha) / 2;

    if ((beta - alpha) < eps) {                       /* Wenn die Enden des Intervalls weniger als die Genauigkeit auseinanderliegen,   */
        return gamma;                                 /* sind wir fertig und geben den Mittelwert der Grenzen zurück                    */
    }

    /* Wenn das Vorzeichen der Funktion von der linken Intervallgrenze verschieden von dem der rechten Intervallgrenze ist,             *
     * machen wir mit dem Intervall [alpha, gamma] und sonst mit [gamm, beta] weiter.                                                   */

    if (sgn(compute_value_at_gamma(a, b, m, alpha)) != sgn(compute_value_at_gamma(a, b, m, gamma))) {
        gamma = compute_q(a, b, m, eps, alpha, gamma);
    }
    else {
        gamma = compute_q(a, b, m, eps, gamma, beta);
    }
    return gamma;
}

int main() {
  /*
   * These variables correspond to the variables named in the exercise.
   */
  double a, b, eps, alpha, beta, q;
  int m;

  /*
   * Query all needed values from the user.
   */
  printf("Endkapital? ");
  scanf("%lf", &a);
  printf("Jaehrliche Rate? ");
  scanf("%lf", &b);
  printf("Laufzeit (in Jahren)? ");
  scanf("%d", &m);
  printf("Genauigkeit der Loesung? ");
  scanf("%lf", &eps);

  /*
   * Set initial interval as described in the exercise.
   */
  alpha = 1.0e-4;
  beta = 1.0;

  /*
   * Compute the values of q.
   */
  q = compute_q(a, b, m, eps, alpha, beta);


  /*
   * Print out the computed solution.
   */
  printf("Gesuchter Zinssatz ist %.7f %%\n", 100.0*q);

  return 0;
}
