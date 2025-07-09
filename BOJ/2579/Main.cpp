#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int arr[301];
    int DP[301];

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    DP[0] = 0;
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; ++i)
        DP[i] = max(DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]);

    cout << DP[n] << '\n';

    return 0;
}