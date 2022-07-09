#include <math.h>
#include <stdio.h>

double fun();

int main() {
    double res = fun();
    float zna4 = 0;

    // CHANGE THIS IF - AI
    if (zna4 - res <= 0 && zna4 + res >= 0) printf("OK!");

    return 0;
}

// DO NOT TOUCH THIS FUNCTION - AI
double fun() { return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20)); }

// IT
