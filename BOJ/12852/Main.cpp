#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 1000001;
int dp[MAX];
int path[MAX];

void solve()
{
    long long N;
    cin >> N;
    dp[1] = 0;

    for (int i = 2; i <= N; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        path[i] = i - 1;

        if (i % 2 == 0)
        {
            if (dp[i / 2] + 1 < dp[i])
            {
                dp[i] = dp[i / 2] + 1;
                path[i] = i / 2;
            }
        }
        if (i % 3 == 0)
        {
            if (dp[i / 3] + 1 < dp[i])
            {
                dp[i] = dp[i / 3] + 1;
                path[i] = i / 3;
            }
        }
    }
    cout << dp[N] << endl;
    long long current = N;
    while (true)
    {
        cout << current << " ";
        if (current == 1)
        {
            break;
        }
        current = path[current];
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}