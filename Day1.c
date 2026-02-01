//Insert an Element in an Array
#include <stdio.h>

int main() {
    int arr[100], n, pos, element;


    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert the element (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

   
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 1;
    }

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    
    arr[pos - 1] = element;
    n++;

    
    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}