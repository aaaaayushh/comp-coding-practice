#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *arr, int n)
{
    int count = 0;
    int i, j;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (arr[i] > arr[i + 1])
        {
            count = 0;
            break;
        }
    }
    if (count > 0)
        printf("count:%d\n", count);
    else
    {
        for (i = 0; i <= n - 2; ++i)
        {

            for (j = 0; j <= n - 2 - i; ++j)
            {
                count++;
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("count:%d\n", count);
    }
}

int main()
{
    int n = 5;
    while (n <= 50)
    {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
        bubblesort(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d  ", arr[i]);
        printf("\n");
        n += 5;
    }
}