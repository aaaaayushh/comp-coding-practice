#include <stdio.h>
#include <stdlib.h>
int gcd(int m, int n)
{
    int t = m < n ? m : n;
    while (1)
    {
        // printf("in loop");

        if (m % t == 0)
        {
            if (n % t == 0)
                return t;
        }
        t -= 1;
    }
}
void main()
{
    int a = gcd(60, 24);
    printf("%d", a);
}