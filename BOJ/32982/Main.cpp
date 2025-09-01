#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    if (!(cin >> N >> K))
        return 0;
    int As, Ae, Bs, Be, Cs, Ce;
    cin >> As >> Ae >> Bs >> Be >> Cs >> Ce;
    long long R1 = Ae;
    for (int day = 1; day <= N; ++day)
    {
        if (R1 < As)
        {
            cout << "NO\n";
            return 0;
        }
        long long R2 = min<long long>(Be, R1 + K);
        // 템플릿 인자 명시해서 두 값을 모두 long long으로 변환해서 비교.
        if (R2 < Bs)
        {
            cout << "NO\n";
            return 0;
        }
        long long R3 = min<long long>(Ce, R2 + K);
        if (R3 < Cs)
        {
            cout << "NO\n";
            return 0;
        }
        if (day == N)
        {
            cout << "YES\n";
            return 0;
        }
        long long nextR1 = min<long long>(Ae, R3 + K - 1440);
        R1 = nextR1;
    }
    cout << "NO\n";
    return 0;
}
