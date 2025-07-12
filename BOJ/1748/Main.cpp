#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt = 0;
    cin >> n;

    if (n < 10)
    {
        cout << n << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i *= 10)
    {
        cnt += n - i + 1;
    }

    cout << cnt << "\n";

    return 0;
}