//check whether the given matrix is an identity matrix or not
#include <stdio.h>

int main() {
    int n, i, j;
    int matrix[10][10];
    int isIdentity = 1;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && matrix[i][j] != 1)
                isIdentity = 0;
            if(i != j && matrix[i][j] != 0)
                isIdentity = 0;
        }
    }

    if(isIdentity)
        printf("Matrix is an Identity Matrix\n");
    else
        printf("Matrix is NOT an Identity Matrix\n");

    return 0;
}

