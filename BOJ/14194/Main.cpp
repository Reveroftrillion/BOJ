#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        long long sum = 0;
        int mn = 101, mx = -1;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        double A = (mn + mx) / 2.0;
        double B = (double)sum / n;

        if (fabs(A - B) < 1.0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
