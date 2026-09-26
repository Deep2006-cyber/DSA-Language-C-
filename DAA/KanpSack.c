#include <stdio.h>

void sort(int n, int p[], int w[])
{
    int i, j, temp;
    float ratio[20], t;

    // Calculate ratio
    for(i = 0; i < n; i++)
    {
        ratio[i] = (float)p[i] / w[i];
    }

    // Sort according to ratio (Descending)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(int n, int p[], int w[], int capacity)
{
    int i;
    float profit = 0.0;

    sort(n, p, w);

    for(i = 0; i < n; i++)
    {
        if(w[i] <= capacity)
        {
            profit = profit + p[i];
            capacity = capacity - w[i];
        }
        else
        {
            profit = profit + ((float)p[i] / w[i]) * capacity;
            break;
        }
    }

    return profit;
}

int main()
{
    int n, p[20], w[20], i, capacity;
    float result;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter profits:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    result = fractionalKnapsack(n, p, w, capacity);

    printf("Maximum Profit = %.2f", result);

    return 0;
}
