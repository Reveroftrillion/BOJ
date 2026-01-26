#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int,int>> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    set<pair<int,int>> slopes;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dy = p[j].second - p[i].second;
            int dx = p[j].first  - p[i].first;

            if (dx == 0) {
                slopes.insert({1, 0});   // 수직선
            } else if (dy == 0) {
                slopes.insert({0, 1});   // 수평선
            } else {
                int g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;
                if (dx < 0) {  // 부호 통일
                    dy = -dy;
                    dx = -dx;
                }
                slopes.insert({dy, dx});
            }
        }
    }

    cout << slopes.size() << "\n";
    return 0;
}
