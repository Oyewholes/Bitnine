#include <stdio.h>

int fibonacci_recursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return fibonacci_recursive(n/3) * fibonacci_recursive(n/3) * fibonacci_recursive(n/3) + fibonacci_recursive(n/2);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = fibonacci_recursive(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}




#include <stdio.h>

#define MAX_SIZE 1000

int memo[MAX_SIZE];

int fibonacci_top_down(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (memo[n] != -1) {
        return memo[n];
    } else {
        memo[n] = fibonacci_top_down(n/3) * fibonacci_top_down(n/3) * fibonacci_top_down(n/3) + fibonacci_top_down(n/2);
        return memo[n];
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Initialize the memoization array with -1
    for (int i = 0; i < MAX_SIZE; i++) {
        memo[i] = -1;
    }

    int result = fibonacci_top_down(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}





#include <stdio.h>

#define MAX_SIZE 1000

int fibonacci_bottom_up(int n) {
    int dp[MAX_SIZE];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i/3] * dp[i/3] * dp[i/3] + dp[i/2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = fibonacci_bottom_up(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}
