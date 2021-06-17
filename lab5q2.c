#include <stdio.h>
#include <stdlib.h>

int queue[100], k1 = 0, k = 0, arr[100][100], n, degree[100];

void calc()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] && i != j)
                degree[i]++;
        }
    }
}

void initQ()
{
    for (int i = 0; i < n; i++)
    {
        queue[i] = -1;
    }
}

void dec(int v)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[v][i])
            degree[i]--;
        if (degree[i] == 0)
            queue[k++] = i;
    }
}

int queueEmpty()
{
    for (int i = 0; i < n; i++)
    {
        if (queue[i] != -1)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    printf("Enter the Number of Vertices : \n");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix : \n");
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    initQ();
    calc();

    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0)
        {
            queue[k++] = i;
        }
    }

    printf("The Topological Sort Order is : \n");

    while (!queueEmpty())
    {
        int vertex = queue[k1++];
        // printf("%d ", vertex);
        queue[k1 - 1] = -1;
        dec(vertex);

        printf("%d ", vertex);
    }

    printf("\n");

    return 0;
}
