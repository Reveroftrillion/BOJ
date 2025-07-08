#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, n, w;
    int cnt = 0;
    int goat, sheep;
    cin >> a >> b >> n >> w;
    for (int i = 1; i < n; i++)
    {
        if (a * i + b * (n - i) == w)
        {
            if (cnt == 2)
            {
                cout << -1 << '\n';
                return 0;
            }
            cnt++;
            sheep = i;
            goat = n - i;
        }
    }
    if (!cnt)
        cout << -1 << '\n';
    else
        cout << sheep << ' ' << goat << '\n';
}