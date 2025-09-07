#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    long long even_first_swaps = 0;
    long long odd_count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 != 0)
        {
            odd_count++;
        }
        else
        {
            even_first_swaps += odd_count;
        }
    }

    long long odd_first_swaps = 0;
    long long even_count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_first_swaps += even_count;
        }
    }

    cout << min(even_first_swaps, odd_first_swaps) << endl;

    return 0;
}