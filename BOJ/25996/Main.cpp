#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long double x;
    cin >> n >> x;

    vector<long double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long double sumsq = 0;
    for (int i = 0; i < n; i++)
        sumsq += a[i] * a[i];

    // total silence
    if (sumsq == 0) {
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << 0;
        }
        cout << '\n';
        return 0;
    }

    long double k = sqrt((long double)n * x / sumsq);

    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << (double)(a[i] * k);
    }
    cout << '\n';
}
