#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, vector<pair<int, int>>> mapSum;
    for (int c = 2; c <= 100; c++)
    {
        int c3 = c * c * c;
        for (int d = c + 1; d <= 100; d++)
        {
            int sum_cd = c3 + d * d * d;
            mapSum[sum_cd].push_back({c, d});
        }
    }

    for (int a = 3; a <= 100; a++)
    {
        int a3 = a * a * a;
        for (int b = 2; b < a; b++)
        {
            int key = a3 - b * b * b;
            auto it = mapSum.find(key);
            if (it == mapSum.end())
                continue;

            for (auto &cd : it->second)
            {
                int c = cd.first;
                int d = cd.second;
                if (b < c && d < a)
                {
                    cout << "Cube = " << a
                         << ", Triple = (" << b << "," << c << "," << d << ")\n";
                }
            }
        }
    }

    return 0;
}
