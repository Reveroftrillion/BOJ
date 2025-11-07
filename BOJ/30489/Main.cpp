#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k))
        return 0;
    vector<long long> s(n);
    long double total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        total += s[i];
    }

    sort(s.begin(), s.end(), greater<long long>());

    int t = min(n, m + k);
    long double done = 0;

    for (int i = 0; i < t; i++)
        done += s[i];

    long double percent = (done / total) * 100.0L;
    cout.setf(std::ios::fixed);                  // 소수점 형식으로 출력하도록 설정
    cout << setprecision(10) << percent << '\n'; // 10자리까지
    return 0;
}
