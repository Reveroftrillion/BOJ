#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    vector<pair<int, int>> pairs;
    for (int i = 0; i < 5; ++i)
        for (int j = i + 1; j < 5; ++j)
            pairs.emplace_back(i, j);

    vector<int> cnt(10, 0);
    int a[5];

    for (int t = 0; t < n; ++t)
    {
        for (int d = 0; d < 5; ++d)
            cin >> a[d];

        for (int k = 0; k < 10; ++k)
        {
            int i = pairs[k].first;
            int j = pairs[k].second;
            if (a[i] == 1 && a[j] == 1)
                ++cnt[k];
        }
    }

    int bestK = 0;
    for (int k = 1; k < 10; ++k)
    {
        if (cnt[k] > cnt[bestK])
            bestK = k;
    }

    cout << cnt[bestK] << '\n';
    int chosen[5] = {0, 0, 0, 0, 0};
    chosen[pairs[bestK].first] = 1;
    chosen[pairs[bestK].second] = 1;
    for (int d = 0; d < 5; ++d)
    {
        if (d)
            cout << ' ';
        cout << chosen[d];
    }
    cout << '\n';
    return 0;
}
