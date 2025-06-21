#include <iostream>
using namespace std;

int A, B, C;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    ans = (A & 15) * 256 + (B & 15) * 16 + (C & 15);
    if (ans < 1000)
        cout << 0;

    if (ans < 100)
        cout << 0;

    if (ans < 10)
        cout << 0;

    cout << ans;
}