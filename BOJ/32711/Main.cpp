#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long sum = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    // 전체 합이 홀수 → 홀수로 나누기 가능
    if (sum % 2 == 1) {
        cout << 1;
        return 0;
    }

    // 전체 합이 짝수 → 짝수로 나누기 시도
    long long prefix = 0;
    for (int i = 0; i < N - 1; i++) {
        prefix += A[i];
        if (prefix % 2 == 0) {
            cout << 1;
            return 0;
        }
    }

    // 나눌 수 없음
    cout << 0;
    return 0;
}
