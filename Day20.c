#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;

    // Har starting index ke liye
    for(int i = 0; i < n; i++) {
        int sum = 0;

        // i se aage tak check karo
        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                count++;
            }
        }
    }

    printf("%lld\n", count);

    return 0;
}
