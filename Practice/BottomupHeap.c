#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n)
{
    int i, k, v, heapify, j;
    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = arr[k];
        heapify = 0;
        while (!heapify && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n) // there are two children
            {
                if (arr[j] < arr[j + 1])
                    j = j + 1;
            }
            if (v >= arr[j])
                heapify = 1;
            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
        // for (int h = 1; h <= n; h++)
        //     printf("%d   ", arr[h]);
        // printf("\n");
    }
    return;
}
void main()
{
    int h[20], i, n;

    printf("\nEnter the number of Elements:");
    scanf("%d", &n);
    printf("\nEnter the Elements:");
    for (i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    printf("\ndisplay the array:");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", h[i]);
    }
    heapify(h, n);
    printf("\nThe heap created:");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", h[i]);
    }
    printf("\n");
}