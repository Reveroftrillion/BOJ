#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    if (!(cin >> n))
        return 0;
    unsigned long long p = 1;
    long long shifts = 0;
    while (p < n)
    {
        p <<= 1;
        shifts++;
    }
    cout << (shifts + 1) << '\n';
    return 0;
}
