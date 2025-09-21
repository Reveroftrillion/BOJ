#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while ((cin >> n))
    {
        // 대각선 d 찾기: T_d = d(d+1)/2 >= n
        long double nd = n;
        long long d = (long long)floor((sqrtl(8.0L * nd + 1.0L) - 1.0L) / 2.0L);
        // 보정 (부동소수 오차 대비)
        while (d * (d + 1) / 2 < n)
            ++d;
        while ((d - 1) > 0 && (d - 1) * d / 2 >= n)
            --d;

        long long Td = d * (d + 1) / 2;
        long long offset = Td - n;

        long long num, den;
        if (d % 2 == 0)
        {
            num = d - offset;
            den = 1 + offset;
        }
        else
        {
            num = 1 + offset;
            den = d - offset;
        }

        cout << "TERM " << n << " IS " << num << "/" << den << "\n";
    }
    return 0;
}
