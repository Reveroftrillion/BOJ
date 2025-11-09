#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < i; ++j)
        {
            if (A[j] < A[i])
                ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}
