#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R;
    if (!(cin >> N >> L >> R)) return 0;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int l = L - 1, r = R - 1;

    for (int i = 0; i+1 <= l-1; ++i) {
        if (A[i] > A[i+1]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    for (int i = r+1; i+1 < N; ++i) {
        if (A[i] > A[i+1]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    long long seg_min = A[l], seg_max = A[l];
    for (int i = l; i <= r; ++i) {
        seg_min = min(seg_min, A[i]);
        seg_max = max(seg_max, A[i]);
    }

    if (l-1 >= 0 && A[l-1] > seg_min) {
        cout << 0 << '\n';
        return 0;
    }
    if (r+1 < N && seg_max > A[r+1]) {
        cout << 0 << '\n';
        return 0;
    }

    cout << 1 << '\n';
    return 0;
}
