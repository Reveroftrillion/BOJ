#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    long long ans = 1;
    for (long long i = 0; i < N; ++i)
    {
        long long a;
        cin >> a;
        if (a == 0)
            a = 1;
        ans = (ans * (a % M)) % M;
    }

    cout << (ans % M) << '\n';
    return 0;
}