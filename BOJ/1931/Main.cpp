#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 끝나는 시간 기준 정렬
    sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    long long last_end = 0;
    int count = 0;

    for (auto &m : meetings) {
        if (m.first >= last_end) {
            count++;
            last_end = m.second;
        }
    }

    cout << count << "\n";
    return 0;
}
