#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> A;
    A.reserve(N + 1);
    A.push_back(0);
    for (int i = 0; i < N; ++i)
    {
        long long x;
        cin >> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());

    long long ans = 0;
    int L = 0, R = (int)A.size() - 1;
    int need = K + 1;
    while (need > 1)
    {
        ans += A[R] - A[L];
        ++L;
        --R;
        need -= 2;
    }
    cout << ans << '\n';
    return 0;
}
