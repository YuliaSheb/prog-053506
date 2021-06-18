#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>
void matrix(double** a, double* b, int n)
{    
    for (int i = 0; i < n; i++) {
        a[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", (i + 1), (j + 1));
            scanf_s("%lf", &a[i][j]);
        }
    } 
    for (int i = 0; i < n; i++) {
        printf("b[%d] = ", i + 1);
        scanf_s("%lf", &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf * x %d ", a[i][j], j);
            if (j < n - 1)
                printf("+ ");
        }
        printf(" = %lf", b[i]);
        printf("\n");
    }
}
double* gauss(double** a, double* b, double* x, int n)
{
    double max;
    int k, index;
    const double e = 0.00001; 
    k = 0;
    while (k < n)
    {
        max = fabs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (fabs(a[i][k]) > max)
            {
                max = fabs(a[i][k]);
                index = i;
            }
        }
        if (max < e)
        {
            printf( "The solution cannot be obtained due to the null column\n %d  Matrix А", index );;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = b[k];
        b[k] = b[index];
        b[index] = temp;
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (fabs(temp) < e) continue; 
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            b[i] = b[i] / temp;
            if (i == k)  continue; 
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            b[i] = b[i] - b[k];
        }
        k++;
    }
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = b[k];
        for (int i = 0; i < k; i++)
            b[i] = b[i] - a[i][k] * x[k];
    }
    return x;
}
int main()
{
    double* x;
    int n;
    double** a, *b;
    printf( "Enter the number of equations ax = b: ");
    scanf_s("%d",&n);
    a = (double**)malloc(n * sizeof(double));
    b = (double*)malloc(n * sizeof(double));
    x = (double*)malloc(n * sizeof(double));
    matrix(a, b, n);
    gauss(a, b, x, n);
    for (int i = 0; i < n; i++)
        printf( "x[%d] = %lf\n",i,x[i]);
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x);
    return 0;
}