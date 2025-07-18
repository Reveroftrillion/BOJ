#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<int> tree(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());

    long long low = 0;
    long long high = tree[n - 1];
    long long max = 0;

    while (low <= high)
    {
        long long sum = 0;
        long long cut = (low + high) / 2;

        for (int i = 0; i < n; i++)
        {
            if (tree[i] - cut > 0)
                sum += tree[i] - cut;
        }

        if (sum >= m)
        {
            max = cut;
            low = cut + 1;
        }
        else
        {
            high = cut - 1;
        }
    }

    cout << max << '\n';

    return 0;
}
