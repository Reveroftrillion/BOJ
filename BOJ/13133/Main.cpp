#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<int> mom(N + 1), dad(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> mom[i] >> dad[i];
    }
    int M;
    cin >> M;
    vector<bool> dead(N + 1, false);
    for (int i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        if (1 <= x && x <= N)
            dead[x] = true;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (dead[i])
            continue;
        if (mom[i] == 0 || dad[i] == 0)
            continue;
        if (mom[i] < 1 || mom[i] > N)
            continue; // 안전 장치(사실 문제에서는 0 아니면 1..N)
        if (dad[i] < 1 || dad[i] > N)
            continue;
        if (dead[mom[i]] || dead[dad[i]])
            continue;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
