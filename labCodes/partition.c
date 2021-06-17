

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int opcount = 0;

int subs1[5];

int j = 0;
int is_subsetsum(int a[], int n, int sum)
{
    opcount++;
    if (sum == 0)
    {
        //printf("%d ",a[4]);
        return 1;
    }
    if (n == 0 && sum != 0)
        return 0;
    if (a[n - 1] > sum)
    {

        return is_subsetsum(a, n - 1, sum);
    }
    //subs1[i++] = a[n-1];
    if (is_subsetsum(a, n - 1, sum))
    {
        return 1;
    }
    if (is_subsetsum(a, n - 1, sum - a[n - 1]) == 1)
    {
        subs1[j++] = a[n - 1];
        return 1;
    }
}

int find_partition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
        return 0;

    return is_subsetsum(arr, n, sum / 2);
}

int inpart1(int k)
{
    for (int i = 0; i < 5; i++)
    {
        if (k == subs1[i])
            return 1;
    }
    return 0;
}

void printpart1()
{
    printf("Partition-1: ");
    for (int i = 0; i < 5; i++)
    {
        if (subs1[i] != 0)
            printf("%d ", subs1[i]);
    }
    printf("\n");
}

void printpart2(int *a)
{
    printf("Partition-2: ");
    for (int i = 0; i < 5; i++)
    {
        if (!inpart1(a[i]))
        {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5
    printf("The set is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    if (find_partition(arr, n) == 1)
    {
        printf("Parition exists!\n");
        printpart1();
        printpart2(arr);
    }
    else
        printf("Parition does not exist.\n");
    printf("Opcount = %d\n", opcount);

    return 0;
}