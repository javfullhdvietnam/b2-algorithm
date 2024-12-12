#include <stdio.h>

// Helper function to determine if a number is sphenic
int is_sphenic(int n, int factor, int spec, int prime_count) {
    if (n == 1 && spec == 3) return 1; // If exactly 3 distinct prime factors, it's a sphenic number
    if (n == 1 || factor > n) return 0; // Base case: if n is reduced to 1 or no factors are left
    if (n % factor == 0) {
        int count = 0;
        while (n % factor == 0) {
            count++;
            n /= factor;
        }
        if (count == 1) {
            return is_sphenic(n, factor + 1, spec + 1, prime_count + 1);
        }
    }
    return is_sphenic(n, factor + 1, spec, prime_count);
}

// Recursive function to print sphenic numbers in a sequence
void print_sphenic_sequence(int n, int current) {
    if (current > n) return; // Base case: stop recursion if current exceeds n
    if (is_sphenic(current, 2, 0, 0)) {
        printf("%d ", current); // Print if the current number is sphenic
    }
    print_sphenic_sequence(n, current + 1); // Recur for the next number
}

int main() {
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    printf("Sphenic numbers up to %d are: ", n);
    print_sphenic_sequence(n, 2); // Start checking from 2
    return 0;
}
