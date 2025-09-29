#include <bits/stdc++.h>
using namespace std;

// 이거 내가 다시 못 풀 듯.....;;;;

static void print_i128(__int128 x)
{
    if (x == 0)
    {
        cout << 0;
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0)
    {
        s.push_back(char('0' + int(x % 10)));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

static __int128 read_i128()
{
    string s;
    cin >> s;
    int i = 0;
    bool neg = false;
    if (!s.empty() && s[0] == '-')
    {
        neg = true;
        i = 1;
    }
    __int128 v = 0;
    for (; i < (int)s.size(); ++i)
        v = v * 10 + (s[i] - '0');
    return neg ? -v : v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;
        int m = n / 2;

        vector<__int128> a(n + 1, 0);
        __int128 leafSum = 0;

        for (int i = m + 1; i <= n; ++i)
        {
            a[i] = read_i128();
            leafSum += a[i];
        }

        __int128 internalSum = 0;
        for (int i = m; i >= 1; --i)
        {
            a[i] = min(a[2 * i], a[2 * i + 1]);
            internalSum += a[i];
        }

        __int128 ans = leafSum - internalSum;
        print_i128(ans);
        cout << '\n';
    }
    return 0;
}
