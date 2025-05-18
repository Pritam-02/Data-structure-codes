#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[2][2], b[2][2], c[2][2], i, j;
    int P, Q, R, S, T, U, V;

    // Input for Matrix A
    printf("\nEnter the elements of matrix A:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Display Matrix A
    printf("\nMatrix A:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Input for Matrix B
    printf("\nEnter the elements of matrix B:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    // Display Matrix B
    printf("\nMatrix B:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    // Applying Strassen’s Algorithm
    P = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    Q = (a[1][0] + a[1][1]) * b[0][0];
    R = a[0][0] * (b[0][1] - b[1][1]);
    S = a[1][1] * (b[1][0] - b[0][0]);
    T = (a[0][0] + a[0][1]) * b[1][1];
    U = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    V = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    // Computing the resulting matrix C
    c[0][0] = P + S - T + V;
    c[0][1] = R + T;
    c[1][0] = Q + S;
    c[1][1] = P + R - Q + U;

    // Display the Resultant Matrix
    printf("\n Matrix Multiplication using Strassen's Algorithm:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}