#include <stdio.h>

int integerSquareRoot(int n) {
    int low = 0, high = n, mid;
    int ans = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        // To avoid overflow, use long long
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;   // exact square root
        }
        else if (square < n) {
            ans = mid;    // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;  // integer square root
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int result = integerSquareRoot(n);
    printf("Integer square root: %d\n", result);

    return 0;
}