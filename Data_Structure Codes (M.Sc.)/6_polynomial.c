#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 10

void printPoly(int poly[], int deg) 
{
    for (int i = 0; i <= deg; i++) 
    {
        printf("%d*X%d ", poly[i],i);
        if(i<deg)
        {
            printf("+");
        }
    }
    printf("\n");
}
void addPoly(int A[], int B[], int C[], int degA, int degB) 
{
    int maxDeg = degA > degB ? degA : degB;
    for (int i = 0; i <= maxDeg; i++) {
        C[i] = A[i] + B[i];
    }
    printf("Addition result: ");
    printPoly(C, maxDeg);
}

void subtractPoly(int A[], int B[], int C[], int degA, int degB) 
{
    int maxDeg = degA > degB ? degA : degB;
    for (int i = 0; i <= maxDeg; i++) {
        C[i] = A[i] - B[i];
    }
    printf("Subtraction result: ");
    printPoly(C, maxDeg);
}

void multiplyPoly(int A[], int B[], int C[], int degA, int degB) 
{
    int maxDeg = degA + degB;
    for (int i = 0; i <= maxDeg; i++) 
    {
        C[i] = 0;
    }
    for (int i = 0; i <= degA; i++) 
    {
        for (int j = 0; j <= degB; j++) 
        {
            C[i + j] += A[i] * B[j];
        }
    }
    printf("Multiplication result: ");
    printPoly(C, maxDeg);
}

void diffPoly(int A[], int degA) {
    int result[MAX_DEGREE] = {0};
    for (int i = 1; i <= degA; i++) 
    {
        result[i - 1] = A[i] * i;
    }
    printf("Differentiation result: ");
    printPoly(result, degA - 1);
}

int main() {
    int A[MAX_DEGREE] = {0}, B[MAX_DEGREE] = {0}, C[MAX_DEGREE] = {0};
    int degA, degB, choice;

    // Input degrees and coefficients
    printf("Enter degree of polynomial A: ");
    scanf("%d", &degA);
    printf("Enter coefficients of polynomial A (from x^0 to x^%d): ", degA);
    for (int i = 0; i <= degA; i++) 
    {
        scanf("%d", &A[i]);
    }

    printf("Enter degree of polynomial B: ");
    scanf("%d", &degB);
    printf("Enter coefficients of polynomial B (from x^0 to x^%d): ", degB);
    for (int i = 0; i <= degB; i++) 
    {
        scanf("%d", &B[i]);
    }

    // Menu for operations
    printf("Choose an operation:\n");
    printf("1. Add A and B\n");
    printf("2. Subtract B from A\n");
    printf("3. Multiply A and B\n");
    printf("4. Differentiate A\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addPoly(A, B, C, degA, degB);
            break;
        case 2:
            subtractPoly(A, B, C, degA, degB);
            break;
        case 3:
            multiplyPoly(A, B, C, degA, degB);
            break;
        case 4:
            diffPoly(A, degA);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}