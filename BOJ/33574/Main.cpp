#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    vector<long long> S;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (x == 1) {
                sort(S.begin(), S.end()); 
            } else {
                sort(S.begin(), S.end(), greater<>());
            }
        } else {
            int x;
            long long t;
            cin >> x >> t;
            S.insert(S.begin() + x, t);
        }
    }

    cout << S.size() << '\n';
    if (!S.empty()) {
        for (auto v : S) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}
