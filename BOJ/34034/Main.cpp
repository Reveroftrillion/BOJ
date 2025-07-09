#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> prob;
    prob.reserve(N);
    for (int i = 1; i <= N; ++i)
    {
        int d;
        cin >> d;
        prob.push_back({d, i});
    }

    sort(prob.begin(), prob.end());

    ll sum = 0;
    int cnt = 0;
    vector<pair<int, int>> chosen;
    for (auto [d, idx] : prob)
    {
        if (sum + d > K)
            break;
        sum += d;
        ++cnt;
        chosen.push_back({d, idx});
    }

    if (cnt < K - M)
    {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> ans;
    ans.reserve(K);
    for (auto [d, idx] : chosen)
    {
        for (int i = 0; i < d - 1; ++i)
            ans.push_back(0);
        ans.push_back(idx);
    }
    while ((int)ans.size() < K)
        ans.push_back(0);

    for (int i = 0; i < K; ++i)
    {
        if (i)
            cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
