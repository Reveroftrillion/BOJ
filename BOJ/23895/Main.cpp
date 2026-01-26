#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, B;
        cin >> N >> B;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        sort(A.begin(), A.end());

        int cnt = 0;
        long long sum = 0;
        for (int price : A) {
            if (sum + price <= B) {
                sum += price;
                cnt++;
            } else break;
        }

        cout << "Case #" << t << ": " << cnt << "\n";
    }
    return 0;
}
