#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        int n;
        if (!(cin >> n))
            return 0;
        if (n == 0)
            break;
        vector<pair<int, int>> pts(n);
        for (int i = 0; i < n; ++i)
            cin >> pts[i].first >> pts[i].second;
        pair<int, int> center = pts[n / 2];
        int cx = center.first, cy = center.second;
        int stan = 0, ollie = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = pts[i].first, y = pts[i].second;
            if (x == cx || y == cy)
                continue;
            if ((x > cx && y > cy) || (x < cx && y < cy))
                ++stan;
            else
                ++ollie;
        }
        cout << stan << ' ' << ollie << '\n';
    }
    return 0;
}
