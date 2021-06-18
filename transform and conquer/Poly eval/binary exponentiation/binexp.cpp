//O(logn) algo for finding a^n

#include <iostream>
using namespace std;
//recursive function
long long binpower(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = binpower(a, b / 2);
    // cout << "res=" << res << ",b=" << b << '\n';
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

//iterative function
long long iterbinpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        // cout << "b&1 =" << (b & 1) << '\n';
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
        // cout << "b=" << b << '\n';
    }
    return res;
}

int main()
{
    cout << "3^13 = " << iterbinpow(3, 13) << '\n';
    cout << "3^13 = " << binpower(3, 13) << '\n';
    return 0;
}