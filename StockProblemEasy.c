#include<stdio.h>

int main()
{
    int prices[] = {1,2};
    int pricesSize = 2;
    int maxProfits = 0;
for(int i=0;i<pricesSize;i++)
{
    for(int j=i+1;j<pricesSize;j++)
    {
        if(prices[i] < prices[j])
        {
            if(prices[j] - prices[i] > maxProfits)
            {
                maxProfits = prices[j] - prices[i];
            }

        }
    }
}
    printf("The Maximum profit is %d",maxProfits);
    return 0;
}