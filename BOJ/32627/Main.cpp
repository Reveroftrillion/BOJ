#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    vector<vector<int>> pos(26);
    for (int i = 0; i < N; i++) {
        pos[S[i] - 'a'].push_back(i);
    }

    vector<int> ptr(26, 0);
    vector<bool> removed(N, false);

    for (int cnt = 0; cnt < M; cnt++) {
        for (int c = 0; c < 26; c++) {
            if (ptr[c] < (int)pos[c].size()) {
                int idx = pos[c][ptr[c]];
                removed[idx] = true;
                ptr[c]++;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!removed[i]) cout << S[i];
    }
    cout << '\n';

    return 0;
}
