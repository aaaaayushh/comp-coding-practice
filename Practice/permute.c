#include <stdio.h>
#include <string.h>
char *pms[];
int pmsi = 0;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int i, int n)
{
    int j;
    if (i == n)
    {
        // pms[pmsi] = a;
        memcpy(pms[pmsi], a, strlen(a));
        // printf("%s\n", pms[pmsi]);
        pmsi++;
        // printf("%s\n", a);
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j)); //backtrack
        }
    }
}

/* Driver program to test above functions */
int main()
{
    char a[] = "ABC";
    permute(a, 0, 2);
    int i;
    for (i = 0; i < pmsi; i++)
    {
        printf("%s\n", pms[i]);
    }
    return 0;
}