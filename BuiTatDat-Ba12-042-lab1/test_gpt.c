#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n, int i) {
    if (n <= 1) return 0; // Numbers <= 1 are not prime
    if (i == 1) return 1; // Base case: only divisible by 1
    if (n % i == 0) return 0; // Divisible by another number
    return isPrime(n, i - 1);
}

// Function to check if a number is sphenic
int sphenic(int n) {
    int count = 0; // Count of distinct prime factors

    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i, i / 2)) {
            count++; // Found a distinct prime factor

            int power = 0; // Count the number of times i divides n

            while (n % i == 0) {
                n /= i; // Remove all occurrences of this prime factor
                power++;
                if (power > 1) {
                    return 0; // Prime factor occurs more than once
                }
            }
        }
        if (count > 3) return 0; // More than 3 distinct prime factors
    }

    // Return true if exactly 3 distinct prime factors and n is reduced to 1
    return count == 3 && n == 1;
}

int main() {
    int n = 200;
    printf("Sphenic numbers up to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        if (sphenic(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
