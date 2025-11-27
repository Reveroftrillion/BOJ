#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k, T0;
    if (!(cin >> n >> k >> T0))
        return 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int d;
        cin >> d;
        sum += d;
    }
    cout << sum << '\n';
    return 0;
}
