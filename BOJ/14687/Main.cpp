#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int lowCnt = (N + 1) / 2;
    int highCnt = N / 2;

    vector<int> low(a.begin(), a.begin() + lowCnt);
    vector<int> high(a.begin() + lowCnt, a.end());

    reverse(low.begin(), low.end()); // low는 감소

    int li = 0, hi = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            cout << low[li++];
        } else {
            cout << high[hi++];
        }
        if (i + 1 < N) cout << ' ';
    }
    cout << '\n';
}
