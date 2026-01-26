#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N, K, S;
        cin >> N >> K >> S;

        long long restart = K + N;
        long long goBack = 2 * K + N - 2 * S;

        cout << "Case #" << t << ": " << min(restart, goBack) << '\n';
    }
}
