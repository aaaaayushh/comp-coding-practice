// #include <bits/stdc++.h>
// #include <string>
// using namespace std;

// void permute(string a, int l, int r)

// {
//     // Base case
//     if (l == r)
//         cout << a << endl;
//     else
//     {
//         // Permutations made
//         for (int i = l; i <= r; i++)
//         {

//             // Swapping done
//             swap(a[l], a[i]);

//             // Recursion called
//             permute(a, l + 1, r);

//             //backtrack
//             swap(a[l], a[i]);
//         }
//     }
// }

// // Driver Code
// int main()
// {
//     string str = "ABC";
//     int n = str.size();
//     permute(str, 0, n - 1);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<string> pms;

void permute(string a, int l, int r)
{

    if (l == r)
    {
        pms.push_back(a);
    }
    else
    {
        for (int j = l; j <= r; j++)
        {
            swap(a[l], a[j]);
            permute(a, l + 1, r);
            swap(a[l], a[j]);
        }
    }
}

int main()
{
    string a = "ABC";
    permute(a, 0, 2);
    int i;
    for (i = 0; i < pms.size(); i++)
    {
        cout << pms[i] << "\n";
    }
    return 0;
}