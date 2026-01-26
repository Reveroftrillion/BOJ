#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int,int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    const int INF = 1e9;
    int R = INF;

    for (int i = 0; i < N; i++) {
        if (cows[i].second == 1) {
            for (int j = 0; j < N; j++) {
                if (cows[j].second == 0) {
                    R = min(R, abs(cows[i].first - cows[j].first) - 1);
                }
            }
        }
    }

    int ans = 0;
    int last = -INF;

    for (int i = 0; i < N; i++) {
        if (cows[i].second == 1) {
            if (cows[i].first - last > R) {
                ans++;
            }
            last = cows[i].first;
        }
    }

    cout << ans << "\n";
}
