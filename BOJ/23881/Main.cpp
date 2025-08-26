#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int swap_count = 0;

    for (int i = n - 1; i > 0; --i)
    {
        int max_idx = i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (a[j] > a[max_idx])
            {
                max_idx = j;
            }
        }

        if (i != max_idx)
        {
            swap(a[i], a[max_idx]);
            swap_count++;

            if (swap_count == k)
            {
                if (a[i] < a[max_idx])
                {
                    cout << a[i] << " " << a[max_idx] << endl;
                }
                else
                {
                    cout << a[max_idx] << " " << a[i] << endl;
                }
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}