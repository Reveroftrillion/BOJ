#include <bits/stdc++.h>
using namespace std;

int mask(char c) {
    if (c == 'U') return 0;
    if (c == 'R') return 1;
    if (c == 'Y') return 2;
    if (c == 'B') return 4;
    if (c == 'O') return 3; // R + Y
    if (c == 'P') return 5; // R + B
    if (c == 'G') return 6; // Y + B
    if (c == 'A') return 7; // R + Y + B
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        string P;
        cin >> N >> P;

        int ans = 0;

        for (int bit = 0; bit < 3; bit++) {
            bool prev = false;
            for (int i = 0; i < N; i++) {
                bool cur = (mask(P[i]) & (1 << bit));
                if (cur && !prev) ans++;
                prev = cur;
            }
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}
