#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    while (cin >> N)
    {
        if (N == 0)
            break;
        long long ans = N * (N + 1) * (2 * N + 1) / 6;
        cout << ans << '\n';
    }
    return 0;
}
