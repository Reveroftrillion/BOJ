#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, q, num, sum;
    cin >> t;

    if (t == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    q = round(t * 0.15);
    num = t - 2 * q;
    sum = 0;
    multiset<int> opinion;

    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        opinion.insert(k);
    }
    for (int j = 0; j < q; j++)
    {
        opinion.erase(opinion.begin());
        auto it = opinion.end();
        --it;
        opinion.erase(it);
    }
    for (int k : opinion)
    {
        sum += k;
    }
    cout << round((double)sum / num) << '\n';
}