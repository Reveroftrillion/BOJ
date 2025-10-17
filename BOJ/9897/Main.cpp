#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, G, R;
    if (!(cin >> L >> G >> R))
        return 0;

    unordered_map<string, pair<int, int>> mp;
    for (int i = 0; i < G; ++i)
    {
        string name;
        int a0, d;
        cin >> name >> a0 >> d;
        mp[name] = {a0, d};
    }

    vector<bool> lamp(L + 1, false);
    for (int i = 0; i < R; ++i)
    {
        string name;
        cin >> name;
        auto it = mp.find(name);
        if (it == mp.end())
            continue;
        int a0 = it->second.first;
        int d = it->second.second;
        for (int pos = a0; pos <= L; pos += d)
        {
            lamp[pos] = !lamp[pos];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= L; ++i)
        if (lamp[i])
            ++cnt;
    cout << cnt << '\n';
    return 0;
}
