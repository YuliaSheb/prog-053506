#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int a; 
void dlina(int a) {
    int d;
    d = 6 * a;
    printf("Derivation of the total length of all edges of the tetrahedron : ");
    printf("%d", d);
    printf("\n");
}
void area(int a){
    double areas;
    areas = pow(a, 2) * sqrt(3);
    printf("The area of ​​all faces of the tetrahedron = %lf", areas);
    printf("\n");
}
void volume(int a) {
    double vol;
    vol = pow(a,2) / (6 * sqrt(2));
    printf("Tetrahedron volume = %lf", vol);
    printf("\n");
}
void height(int a) {
    double h;
    h = a * sqrt(2 / 3);
    printf("Tetrahedron height = %lf",  h);
    printf("\n");
}
void radius(int a) {
    double r;
    r = a / (2 * sqrt(3));
    printf("The radius of the inscribed sphere = %lf",r);
    printf("\n");
}
void information() {
    printf("The author of the program - Shebeko Julia");
}
int Info() {
    int i;
    printf("Menu:\n");
    printf("1.Enter the length of the edge of the tetrahedron. \n");
    printf("2.Derivation of the total length of all edges of the tetrahedron.\n");
    printf("3.Derivation of the area of all faces of the tetrahedron.\n");
    printf("4.Tetrahedron volume derivation.\n");
    printf("5.Conclusion of the tetrahedron height.\n");
    printf("6.Derivation of the radius of the inscribed sphere.\n");
    printf("7.Information about the version and the author of the program.\n");
    printf("8.The task 2.2(6).\n");
    printf("9.Exit.\n");
    scanf_s("%i", &i);
    printf("\n");
    return i;
}
double factorial(int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int Sin_recurs(double x, double e)
{
    int n = 1;
    double value = 0;
    if (fabs(sin(x) - value) < e)
    {
        printf("\n1) sin(x) = %lf.\n", sin(x));
        return n;
    }
    n++;
    value += pow(-1, (double)(n - 1)) * pow(x, (double)(2 * n - 1)) / factorial(2 * n - 1);
    return Sin_recurs(x, e);
}

int Sin_iter(double x, double e)
{
    int n = 1;
    double value = 0;
    while ((fabs(sin(x) - value) > e))
    {
        n++;
        value += pow(-1, (double) (n - 1)) * pow(x, (double)(2 * n - 1)) / factorial(2 * n - 1);
    }

    printf("\n2) sin(x) = %lf.\n", sin(x));
    return n;
}
int main()
{
    while (1) {
        switch (Info()) {
        case 1:  printf("Enter the length of the edge of the tetrahedron:");
            scanf_s("%d", &a);
            while (a <= 0)
            {
                printf("Rib length cannot be less than 1.");
                printf("Enter the length of the edge of the tetrahedron:");
                scanf_s("%d", &a);
            };  break;
        case 2: dlina(a); break;
        case 3: area(a); break;
        case 4: volume(a); break;
        case 5: height(a); break;
        case 6: radius(a); break;
        case 7: information(); break;
		case 8:
            double x, e;
            printf("Enter x: ");
            scanf_s("%lf.", &x);
            printf("Enter e: ");
            scanf_s("%lf", &e);
            Sin_recurs(x, e);
            Sin_iter(x, e);
            return 0;
			break;
        case 9: printf("Bye\n"); return 0;
        default: printf("You are a bold one. Try again!"); printf("\n"); return 0; break;
        }
    }
    return 0;
}