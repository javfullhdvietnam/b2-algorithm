#include <stdio.h>

int is_prime(int num, int divisor) {
    if (num < 2) return 0; // 0 and 1 are not prime numbers
    if (divisor == 1) return 1; // Base case: if divisor is 1, it's a prime number
    if (num % divisor == 0) return 0; // If divisible by any number other than 1 and itself, not prime
    return is_prime(num, divisor - 1); // Recursively check for smaller divisors
}

void print_primes(int n, int current) {
    if (current > n) return; // Base case: if current exceeds n, stop recursion
    if (is_prime(current, current - 1)) {
        printf(" %d", current); // Print the current number if it is prime
    }
    print_primes(n, current + 1); // Recur for the next number
}

int main() {
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    printf("Prime numbers are:");
    print_primes(n, 2); // Start from 2, as it's the first prime number
    return 0;
}
