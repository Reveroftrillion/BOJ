#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<long> plus(1000001, 0);
    vector<long> minus(1000001, 0);
    long t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long k;
        cin >> k;
        if (k >= 0)
        {
            plus[k]++;
        }
        else
        {
            k *= -1;
            minus[k]++;
        }
    }
    for (int i = 1000000; i >= 1; i--)
    {
        for (int j = 0; j < minus[i]; j++)
        {
            cout << -i << '\n';
        }
    }
    for (int j = 0; j <= 1000000; j++)
    {
        for (int k = 0; k < plus[j]; k++)
        {
            cout << j << '\n';
        }
    }
}