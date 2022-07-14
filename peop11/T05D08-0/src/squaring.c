#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main()
{
    int n, data[NMAX];  // дата - название массива, с максимальным числом элементов = 10 ,,
   //( n - введенное число элементов)
    if (input(data, &n) != -1) {
        squaring(data, n);
        output(data, n);
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

void output(int *a, int n)
{
    for(int *p = a; p - a < n; p++)
    {
        printf("%d ", *p);
    }
}

void squaring(int *a, int n)
{
    for ( int *p = a; p - a < n; p++ )
    {
        *p = *p * *p;
    }
}


