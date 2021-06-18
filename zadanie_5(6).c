#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct service
{
    int serviceTime;
    int number;
    struct service* next;
    struct service* prev;
} Service;

void BSrt(Service* serv);

void AddService(Service* serv, int number);

int Result(Service* serv, int maxSum);

void AddService(Service* serv, int number) {

    Service* p = (Service*)malloc(sizeof(Service));
    if (p == NULL) {
        exit(2);
    }
    p->serviceTime = rand() % 100;
    p->prev = serv;
    p->next = NULL;
    p->number = number;
    serv->next = p;
}

void BSrt(Service* serv) {

    Service* temp = serv;
    Service* tempNext = temp->next;
    int tr = 1;
    while (tr) {
        tr = 0;

        while (serv->next) {

            if (serv->serviceTime > tempNext->serviceTime) {
                tr = 1;
                int tempST = serv->serviceTime;
                int tempNumber = serv->number;
                serv->serviceTime = tempNext->serviceTime;
                serv->number = tempNext->number;
                tempNext->serviceTime = tempST;
                tempNext->number = tempNumber;
            }

            serv = serv->next;
            tempNext = serv->next;
        }

        while (serv->prev) {
            serv = serv->prev;
        }
        tempNext = serv->next;
    }
}
int Result(Service* serv, int maxSum) {

    int servSum = 0, answ = 0, i = 1;
    printf("\nRoute: ");
    while (serv) {

        servSum += serv->serviceTime;
        if (servSum < maxSum) {
            printf("%d ", serv->number);
            answ += i * serv->number;
        }
        else {
            break;
        }
        serv = serv->next;
        i *= 10;
    }
    return answ;
}

int main() {

    srand(time(NULL));
    int numberOfStructures = 0;
    int maxSum;
    Service* serv = (Service*)malloc(sizeof(Service));
    if (serv == NULL) {
        exit(2);
    }
    serv->serviceTime = rand() % 100;
    serv->next = NULL;
    serv->prev = NULL;
    serv->number = 0;
    Service* first = serv;

    printf("Enter N - number of services\n");
    scanf("%d", &numberOfStructures);
    printf("Enter T - time\n");
    scanf("%d", &maxSum);
    for (int i = 1; i < numberOfStructures; i++) {

        AddService(serv, i);
        serv = serv->next;
    }
    serv = first;

    while (serv) {
        printf("%d - %d  ", serv->number, serv->serviceTime);
        serv = serv->next;
    }
    serv = first;
    printf("\n");

    BSrt(serv);
    serv = first;

    while (serv) {
        printf("%d - %d  ", serv->number, serv->serviceTime);
        serv = serv->next;
    }

    serv = first;
    int servSum = 0;
    maxSum = Result(serv, maxSum);
    free(serv);
    return 0;
}