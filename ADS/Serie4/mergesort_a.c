void mergesort(int n, int *x, int *h) {
    int *y, *z, *hy, *hz;
    int m;
    int i, j, k;
    if(n > 1) {
        m = n / 2;
        y = h; z = h + m;
        hy = x; hz = x + m;
        for(i=0; i<n; i++) h[i] = x[i];
        mergesort(m, y, hy);
        mergesort(n-m, z, hz);
        j = 0; k = 0;
        for(i=0; i<n; i++)
            if(j == m || (k+m < n && y[j] > z[k])) {
                x[i] = z[k]; k++;
        }
        else {
            x[i] = y[j]; j++;
        }
    }
}
