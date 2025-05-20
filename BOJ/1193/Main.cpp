#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int cnt = 1;
    int sum = 0;

    while (sum + cnt < t)
    {
        sum += cnt;
        cnt++;
    }

    int num = t - sum;

    if (cnt % 2 == 0)
    {
        cout << num << "/" << cnt - num + 1 << "\n";
    }
    else
    {
        cout << cnt - num + 1 << "/" << num << "\n";
    }

    return 0;
}
