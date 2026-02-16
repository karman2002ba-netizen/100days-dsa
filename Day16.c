//  count the frequency of elements in an array
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 2, 3, 4, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int freq[100] = {0}; 

    for(int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    for(int i = 0; i < 100; i++) {
        if(freq[i] != 0) {
            printf("%d occurs %d times\n", i, freq[i]);
        }
    }

    return 0;
}
