#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long Mlim, Plim;
    cin >> N >> Mlim >> Plim;

    int Ntot = 2 * N;
    long long M = 1LL * N * N;

    cout << Ntot << " " << M << "\n";

    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j <= 2 * N; j++) {
            cout << i << " " << j << "\n";
        }
    }

    return 0;
}
