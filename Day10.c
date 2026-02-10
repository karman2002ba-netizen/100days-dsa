//Check palindrome
#include <stdio.h>

int main() {
    int num, temp, rev = 0, rem;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (num != 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    if (temp == rev)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}
