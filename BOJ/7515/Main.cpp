#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    vector<unsigned long long> a(41);
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i <= 40; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        cin >> n;
        cout << "Scenario " << tc << ":\n"
             << a[n] << "\n\n";
    }
    return 0;
}
