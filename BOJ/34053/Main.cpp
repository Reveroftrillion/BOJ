#include <iostream>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long sum = 0;
    long long mn = LLONG_MAX;

    for (int i = 0; i < N * M; ++i)
    {
        long long x;
        cin >> x;
        sum += x;
        if (x < mn)
            mn = x;
    }

    cout << sum - mn << '\n';
    return 0;
}
