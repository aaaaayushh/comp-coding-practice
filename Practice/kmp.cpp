#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
void computeLPS(char *pattern, int m, int *lps);

void kmpsearch(char *pattern, char *txt)
{
    int m = strlen(pattern);
    int n = strlen(txt);

    //create lps[] that will hold the longest prefix suffix values for pattern
    int lps[m];
    computeLPS(pattern, m, lps);

    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (pattern[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern at index:" << i - j << endl;
            j = lps[j - 1];
        }
        //mismatch after j matches
        else if (i < n && pattern[j] != txt[i])
        {
            //do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

void computeLPS(char *pattern, int m, int *lps)
{
    //length of the previous longest prefix suffix
    int len = 0;
    lps[0] = 0;
    //the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        //pattern[i] != pattern[len]
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    kmpsearch(pat, txt);
    return 0;
}