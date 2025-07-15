#include <iostream>
#include <vector>
using namespace std;

long long memo[1001];

long long dp(int n)
{
    if (memo[n] != 0)
        return memo[n];
    if (n == 0 || n == 1)
        return memo[n] = 1;
    return memo[n] = (dp(n - 1) + dp(n - 2) * 2) % 10007;
}

int main()
{
    int n;
    cin >> n;
    cout << dp(n) << '\n';
    return 0;
}