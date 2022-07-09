#include <math.h>
#include <stdio.h>

int read_number();

int mod(int dividend, int divisor);

int is_prime(int num);

int main() {
    int num;
    num = read_number();
    if ((num == 0) || (num == 1)) {
        return 0;
    }
    int res = num;
    while (res >=1) {
        if (is_prime(res) && mod(num, res)) {
            printf("%d", res);
            return 0;
        }
        res = res - 1;
    }
}

int read_number() {
    int num;
    char enter;
    if ((scanf("%d%c", &num, &enter) == 2) && (enter == '\n')) {
        if ((num == 0) || (num == 1)) {
            printf("n/a");
        }
        if (num < 0) {
            num = num * (-1);
        }
        return num;
    } else {
        printf("n/a");
        return 0;
    }
}
int mod(int dividend, int divisor) {
    double res = dividend * pow(divisor, -1);
    // printf("%lf", res);
    while (res >= 1) {
        res = res - 1;
    }
    // делится без остатка
    if (res == 0) {
        return 1;
    } else {
        return 0;
    }
}

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++)
        if (mod(num, i))
            return 0;
    return 1;
}

