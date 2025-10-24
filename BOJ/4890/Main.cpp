#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long W, H;
    while (cin >> W >> H)
    {
        if (W == 0 && H == 0)
            break;
        long long g = std::gcd(W, H);
        cout << (W / g) * (H / g) << '\n';
    }
    return 0;
}
