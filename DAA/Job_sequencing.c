#include <stdio.h>

#define MAX 10

int main()
{
    int n, i, j, temp;
    int maxDeadline = 0, totalProfit = 0;

    char id[MAX], result[MAX];
    int deadline[MAX], profit[MAX], slot[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Job ID, Deadline and Profit: ");
        scanf(" %c %d %d", &id[i], &deadline[i], &profit[i]);

        if(deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    // Sort jobs according to profit (descending)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(profit[i] < profit[j])
            {
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;

                char c = id[i];
                id[i] = id[j];
                id[j] = c;
            }
        }
    }

    // Initialize slots
    for(i = 0; i < maxDeadline; i++)
    {
        slot[i] = 0;
    }

    // Greedy Job Sequencing
    for(i = 0; i < n; i++)
    {
        for(j = deadline[i] - 1; j >= 0; j--)
        {
            if(slot[j] == 0)
            {
                slot[j] = 1;
                result[j] = id[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    printf("\nSelected Job Sequence: ");

    for(i = 0; i < maxDeadline; i++)
    {
        if(slot[i] == 1)
        {
            printf("%c ", result[i]);
        }
    }

    printf("\nMaximum Profit = %d\n", totalProfit);

    return 0;
}