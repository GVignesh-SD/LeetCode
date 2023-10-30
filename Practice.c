#include<stdio.h>
#include<string.h>

void bubbleSort(char *names[], int n)
{
    int i,j;
    char *temp;

    for(int i=0;i<n-1;i++)
    {
        int swapped = 0;
        for(int j=0;j<n-i-1;j++)
        {
            if(strcmp(names[j],names[j+1]) < 0)
            {
                temp = names[j];
                names[j] = names[j+1];
                names[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0)
        {
            break;
        }
    }
}


int main()
{
     char *names[] = {"Bob", "Steve", "Patrick", "Davie"};
    int n = sizeof(names) / sizeof(names[0]);

    printf("Original Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    bubbleSort(names, n);

    printf("\nSorted Names in Ascending Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}