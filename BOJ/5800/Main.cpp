#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    for (int i = 1; i <= K; i++) {
        int N;
        cin >> N;

        vector<int> scores(N);
        for (int j = 0; j < N; j++) {
            cin >> scores[j];
        }

        sort(scores.begin(), scores.end(), greater<int>());

        int mx = scores[0];
        int mn = scores[N - 1];

        int largest_gap = 0;
        for (int j = 0; j < N - 1; j++) {
            largest_gap = max(largest_gap, scores[j] - scores[j + 1]);
        }

        cout << "Class " << i << "\n";
        cout << "Max " << mx << ", Min " << mn
             << ", Largest gap " << largest_gap << "\n";
    }

    return 0;
}
