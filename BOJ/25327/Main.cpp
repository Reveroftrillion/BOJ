#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;
    unordered_map<string, int> cnt;
    cnt.reserve(n * 8 * 2);

    vector<string> items(3);
    for (int i = 0; i < n; ++i)
    {
        cin >> items[0] >> items[1] >> items[2]; // subject fruit color
        // 모든 와일드카드 조합(0..7)
        for (int mask = 0; mask < 8; ++mask)
        {
            string key;
            for (int k = 0; k < 3; ++k)
            {
                if (mask & (1 << k))
                    key += "-";
                else
                    key += items[k];
                if (k < 2)
                    key.push_back(' ');
            }
            ++cnt[key];
        }
    }

    string q0, q1, q2;
    for (int i = 0; i < m; ++i)
    {
        cin >> q0 >> q1 >> q2;
        string qkey = q0 + " " + q1 + " " + q2;
        auto it = cnt.find(qkey);
        if (it == cnt.end())
            cout << 0 << '\n';
        else
            cout << it->second << '\n';
    }
    return 0;
}
