#include <stdio.h>
#include <math.h>

// Function to count the number of digits in an integer
int num_digits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return (count == 0) ? 1 : count;
}

// Karatsuba multiplication function
long long karatsuba(long long x, long long y) {
    // Base case: If x or y is small, multiply directly
    if (x < 10 || y < 10)
        return x * y;

    // Determine the maximum length of the numbers
    int n = max(num_digits(x), num_digits(y));
    int half = n / 2;

    // Split the numbers into two halves
    long long a = x / pow(10, half);  // Left part of x
    long long b = x % (long long)pow(10, half);  // Right part of x
    long long c = y / pow(10, half);  // Left part of y
    long long d = y % (long long)pow(10, half);  // Right part of y

    // Recursively compute three products
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

    // Return the final product using Karatsuba's formula
    return ac * pow(10, 2 * half) + (ad_plus_bc * pow(10, half)) + bd;
}

int main() {
    long long num1, num2, result;

    // Taking user input
    printf("Enter first integer: ");
    scanf("%lld", &num1);
    
    printf("Enter second integer: ");
    scanf("%lld", &num2);

    // Perform Karatsuba multiplication
    result = karatsuba(num1, num2);

    // Display the result
    printf("Product using Karatsuba multiplication: %lld\n", result);

    return 0;
}
