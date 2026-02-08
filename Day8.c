//Compute Power Using Recursion 
#include <stdio.h>

int power(int x, int n) {
    if (n == 0)
        return 1;
    else
        return x * power(x, n - 1);
}

int main() {
    int base, exponent;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    printf("%d^%d = %d\n", base, exponent, power(base, exponent));

    return 0;
}
