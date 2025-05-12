#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<pair<long, long>> beacon;
    for (int i = 0; i < t; i++)
    {
        long x, y;
        cin >> x >> y;
        beacon.push_back({x, y});
    }

    stable_sort(beacon.begin(), beacon.end(), [](const pair<long, long> &a, const pair<long, long> &b)
                { return a.first < b.first; });

    stable_sort(beacon.begin(), beacon.end(), [](const pair<long, long> &a, const pair<long, long> &b)
                { return a.second < b.second; });

    for (int i = 0; i < t; i++)
    {
        cout << beacon[i].first << " " << beacon[i].second << '\n';
    }
}