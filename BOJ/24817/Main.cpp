#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, m;
    if (!(cin >> n >> p >> m))
        return 0;

    unordered_map<string, int> score;
    score.reserve(n * 2);
    vector<string> names(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> names[i];
        score[names[i]] = 0;
    }

    unordered_set<string> hasWon;
    vector<string> winners;
    for (int i = 0; i < m; ++i)
    {
        string name;
        int pts;
        cin >> name >> pts;
        if (hasWon.find(name) != hasWon.end())
        {
            score[name] += pts;
            continue;
        }
        score[name] += pts;
        if (score[name] >= p)
        {
            winners.push_back(name);
            hasWon.insert(name);
        }
    }

    if (winners.empty())
    {
        cout << "No winner!\n";
    }
    else
    {
        for (auto &w : winners)
        {
            cout << w << " wins!\n";
        }
    }

    return 0;
}
