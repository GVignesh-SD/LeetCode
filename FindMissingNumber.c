#include <stdio.h>

int findMissingNumber(int A[], int n) {
    // Calculate the expected sum of numbers from 1 to n + 1
    int expectedSum = (n + 1) * (n + 2) / 2;

    // Calculate the actual sum of elements in the array
    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += A[i];
    }

    // The missing number is the difference between the expected sum and the actual sum
    int missingNumber = expectedSum - actualSum;
    return missingNumber;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int missingNumber = findMissingNumber(A, n);

    printf("The missing number is: %d\n", missingNumber);

    return 0;
}
