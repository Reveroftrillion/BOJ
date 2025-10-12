#include <bits/stdc++.h>
using namespace std;

vector<long long> nums;

void dfs(long long x, int last_digit)
{
    if (x != -1)
        nums.push_back(x);
    for (int d = 0; d < last_digit; d++)
    {
        long long nx = (x == -1 ? d : x * 10 + d);
        dfs(nx, d);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    dfs(-1, 10);

    sort(nums.begin(), nums.end());

    if (N >= nums.size())
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << nums[N] << "\n";
    }
    return 0;
}
