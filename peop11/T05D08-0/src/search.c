/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/



// Copyright 2022 thuzadca
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int pre_proverka(int *a, int n);
double chet(int *a, int n);
int nenol(int *a, int n);
double ozid(int *a, int n);
double bolozid(int *a, int n);
double proverka(int *a, int n);

 /*chet(data, n) != 1 && 
            nenol(data, n) != 1 && 
            ozid(data, n) != 1 && 
            bolozid(data, n) != 1 ) {
        output(int b); */   

int main()
{
    int n, data[NMAX];
    if ( input(data, &n) != 1) {
        int b = 0; 
        b = proverka(data, n);
        printf("%d", b);
    } else {
        printf("n/a");
    }
    return 0;
}


int input(int *a, int *n)
{
    if ( scanf("%d", n) ==1 && *n > 0 && *n <= NMAX ) {
        for(int *p = a; p - a < *n; p++)
        {
            if (scanf("%d", p) != 1 ) {
                return -1;
            }
        }
    } else {
        return -1;
    }
    return 0;
}


double proverka(int *a, int n)
{
    if (chet(data, n) == 1 && nenol(data, n) == 1 && ozid(data, n) == 1 && bolozid(data, n) == 1)
}












double chet(int *a, int n)
{
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0) {
            
            return *p;
        } 
    }
}