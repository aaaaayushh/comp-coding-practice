#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bfmatch(char *str, char *sub, int n)
{
    // const char *sub = "AAAAB";
    int i = 0, j = 0;
    int count = 0;
    while (i < n)
    {
        count++;
        while (j < strlen(sub) && *(str + i + j) == *(sub + j))
        {
            count++;
            j++;
        }
        if (j == strlen(sub))
        {
            printf("%d\n", count);
            return i;
        }
        else
            j = 0;
        i++;
    }
    printf("count:%d\n", count);
    return -1;
}
int main()
{
    // char a[10] = "aabbbbaa";
    // char b[10] = "aa";
    printf("Enter string and pattern:");
    char a[20];
    char b[20];
    scanf("%s%s", a, b);
    int ans = bfmatch(a, b, strlen(a));
    printf("ans:%d", ans);
}