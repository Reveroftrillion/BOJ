#include <iostream>
using namespace std;

int N;

void yen()
{
    int ans = 0;
    while (N--)
    {
        int x;
        cin >> x;
        if (ans + x < 301)
            ans += x;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N)
    {
        yen();
        cin >> N;
    }
}