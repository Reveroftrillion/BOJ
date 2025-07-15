#include <iostream>
using namespace std;

int sum[100001];

int main(void)
{
    int n, m, a, b, temp;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cout << (sum[b] - sum[a - 1]) << '\n';
    }

    return 0;
}