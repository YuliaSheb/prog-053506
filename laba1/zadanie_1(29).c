#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
char n[100000];
int razmer(char n[])  
{
    int i = 0;
    while (n[i] != '\0') {
        i++;
    }
    return i;
}
int increase(char n[])
{
    for (int i = 1; i < razmer(n); i++) {
        if (n[i - 1] > n[i]) {
            return 0;
        }
    }
    return 1;
}
int waning(char n[])
{
    for (int i = 1; i < razmer(n); i++) {
        if (n[i - 1] < n[i]) {
            return 0;
        }
    }
    return 1;
}
int main(void)
{
    int i;
    printf("Enter a natural number : ");
    gets_s(n);
    if (increase(n) == 1) {
        printf("\nYour number increaset!");
    }
    else if (waning(n) == 1) {
        printf("\nYour number waning!");
    }
    else 
    {
        printf("\nYour number does not increase and does not decrease!!!");
    }
    printf("\n");
    return 0;
}