#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<ll> X(M + 2), Y(M + 2);
    X[0] = 0;
    Y[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        cin >> X[i] >> Y[i];
    }
    X[M + 1] = N + 1;
    Y[M + 1] = 0;

    ll sumY = 0;
    for (int i = 1; i <= M; i++)
        sumY += Y[i];

    vector<ll> dp(M + 2, LLONG_MIN);
    dp[0] = 0;
    for (int i = 1; i <= M + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ll L = X[i] - X[j] - 1;
            ll seg = L * (L + 1) / 2;
            dp[i] = max(dp[i], dp[j] + seg + Y[i]);
        }
    }

    ll answer = dp[M + 1] - sumY;
    cout << answer << "\n";
    return 0;
}
