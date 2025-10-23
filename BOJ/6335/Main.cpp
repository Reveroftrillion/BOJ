#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int caseNo = 1;
    while ((cin >> n))
    {
        if (n == 0)
            break;
        struct Comp
        {
            int a, L, r;
        };
        vector<Comp> v;
        int start = -1;
        for (int i = 0; i < n; ++i)
        {
            int y, a, b;
            cin >> y >> a >> b;
            int L = b - a;
            int r = ((y - a) % L + L) % L;
            v.push_back({a, L, r});
            start = max(start, a);
        }
        int ans = -1;
        for (int Y = start; Y < 10000; ++Y)
        {
            bool ok = true;
            for (auto &c : v)
            {
                if (((Y - c.a) % c.L + c.L) % c.L != c.r)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans = Y;
                break;
            }
        }
        cout << "Case #" << caseNo++ << ":\n";
        if (ans == -1)
            cout << "Unknown bugs detected.\n\n";
        else
            cout << "The actual year is " << ans << ".\n\n";
    }
    return 0;
}
