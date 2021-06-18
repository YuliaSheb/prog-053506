#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int Info() {
    int i;
    printf("\nMenu:\n");
    printf("1.The task 4_1. \n");
    printf("2.The task 4_2.\n");
    printf("3.Exit.\n");
    scanf_s("%i", &i);
    printf("\n");
    return i;
}
//the word size is considered
int size(const char* n) {
    int score = 0;
    while (n[score])
    {
        ++score;
    }
    return score;
}
char* toUpper(char* string) {
    for (int i = 0; i < size(string); ++i) {
        if (string[i] > 96 && string[i] < 123) {
            string[i] -= 32;
        }
        else {
            continue;
        }
    }
    return string;
}

char* toLower(char* string) {
    for (int i = 0; i < size(string); ++i) {
        if (string[i] > 64 && string[i] < 91) {
            string[i] += 32;
        }
        else {
            continue;
        }
    }
    return string;
}

void input(char** a, int value) {
    printf("Fill the first array (length - 5).\n");
    for (int i = 0; i < value; ++i) {
        char str = 0;
        int j = 0;
        printf("Enter word: ");
        while (1) {
            str = getc(stdin);
            if (str == '\n') break;
            a[i][j] = str;
            printf("\n");
            j++;
        }
    }
}


void case_of_letters(char** a,  int value) {

    int score;
    for (int i = 0; i < value; ++i) {
        score = 0;
        toLower(&(*a[i]));
        for (int j = 0; j < value; ++j) {
            for (int k = 0; k < value; ++k) {
                if (a[i][j] == a[i][k]) ++score;
            }
        }
        if (score == value) toUpper(&(*a[i]));
    }
}
void output(char** a,  int value) {
    printf("\n");
    for (int i = 0; i < value; ++i) {
        for (int j = 0; j < value; ++j) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int value;
    printf("Enter word size in matrix:");
    scanf_s("%d", &value);
    char** matrix = (char**)malloc(value * sizeof(char*));
    for (int i = 0; i < value; i++) {
         matrix[i] = (char*)malloc(value * sizeof(char));
    }
    FILE* in;
    char** array = (char**)malloc(100 * sizeof(char*));
    for (int i = 0; i < 100; i++)
    {
        array[i] = (char*)malloc(80 * sizeof(char));
        if (!array[i])
        {
            for (i -= 1; i >= 0; i--)
            {
                free(array[i]);
                array[i] = NULL;
            }
            free(array);
            array = NULL;
            exit(1);
        }
    }
    if (!array)
    {
        printf("Error\n");
        exit(1);
    }
    int score = 0;
    while (1) {
        switch (Info()) {
        case 1:
            input(matrix, value);
            case_of_letters(matrix, value);
            output(matrix, value);
            break;
        case 2:
            in = fopen("test.txt", "r+");
            if (in == NULL)
            {
                printf("Error, file is closed!\n");
                return -1;
            }
            else {
                printf("File is opened!\n");
            }
            while (!feof(in)) {
                fgets(array[score], 80, in);
                ++score;
            }
            rewind(in);
            int add;
            for (int i = 0; i < score; ++i) {
                add = size(array[i]);
                add = (80 - add) / 2;
                for (int j = 0; j < add; j++) {
                    fputc(' ', in);
                }
                fputs(array[i], in);
            }
            break;
        case 3: printf("Bye, see you later mate\n"); return 0;
        default: printf("You are a bold one. Try again!"); printf("\n"); return 0; break;
        }
    }
        for (int i = 0; i < value; i++) {
            free(matrix[i]);
        }
        free(matrix);
        for (int i = 0; i < 100; i++) {
            array[i] = NULL;
            free(array[i]);
        }
        array = NULL;
        free(array);
        fclose(in);
    return 0;
}