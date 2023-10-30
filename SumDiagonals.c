#include<stdio.h>

int sumDiagonals(int **array, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum = sum + (array[i][i]) + (array[i][n-1-i]);
    }
    return sum;
}

int main()
{
    int n = 4;  // Number of rows (and columns) in the square array
    int array[4][4] = {
        {1, 2, 3, 1},
        {2, 7, 3, 2},
        {1, 8, 4, 5},
        {2, 3, 4, 6}
    };

    int *arrayPtr[4];
    for (int i = 0; i < 4; i++) {
        arrayPtr[i] = array[i];
    }

    int result = sumDiagonals(arrayPtr,n);
    printf("The Sum of Diagonals is : %d",result);

    return 0;
}