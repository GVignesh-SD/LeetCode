#include <stdio.h>

int numWaysToClimbUp(int n) {
    int dp[n + 1];

    // Initialize the base cases
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        // The number of ways to reach step i is the sum of ways to reach
        // the previous three steps (i-1, i-2, and i-3) because you can
        // skip a maximum of 2 stairs at a time.
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n;

    printf("Enter the number of stairs: ");
    scanf("%d", &n);

    int ways = numWaysToClimbUp(n);
    printf("Number of ways to climb up the staircase: %d\n", ways);

    return 0;
}
