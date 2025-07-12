#include <iostream>
using namespace std;

int dp(int k)
{
    if (k == 1)
        return 1;
    else if (k == 2)
        return 2;
    else if (k == 3)
        return 4;
    else
    {
        return dp(k - 1) + dp(k - 2) + dp(k - 3);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int k;
        cin >> k;
        cout << dp(k) << '\n';
    }
}