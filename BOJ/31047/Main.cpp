#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int N;
        cin >> N;
        map<string, int> cnt;
        for (int i = 0; i < N; ++i)
        {
            string name;
            int k;
            cin >> name >> k;
            cnt[name] += k;
        }

        vector<pair<string, int>> v;
        v.reserve(cnt.size());
        for (auto &p : cnt)
            v.emplace_back(p.first, p.second);

        sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             {
                 if (a.second != b.second)
                     return a.second > b.second; 
                 return a.first < b.first; });

        cout << v.size() << '\n';
        for (auto &p : v)
        {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}
