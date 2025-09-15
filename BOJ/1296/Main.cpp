#include <bits/stdc++.h>
using namespace std;

struct love
{
    int L = 0, O = 0, V = 0, E = 0;
};

love lovecnt(const string &s)
{
    love c;
    for (char ch : s)
    {
        if (ch == 'L')
            ++c.L;
        else if (ch == 'O')
            ++c.O;
        else if (ch == 'V')
            ++c.V;
        else if (ch == 'E')
            ++c.E;
    }
    return c;
}

int score(const love &base, const string &team)
{
    love t = lovecnt(team);
    long long L = base.L + t.L;
    long long O = base.O + t.O;
    long long V = base.V + t.V;
    long long E = base.E + t.E;
    long long s = (L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E);
    return (int)(s % 100);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string light_green;
    int N;
    if (!(cin >> light_green))
        return 0;
    cin >> N;

    vector<string> teams(N);
    for (int i = 0; i < N; ++i)
        cin >> teams[i];

    love base = lovecnt(light_green);

    int bestScore = -1;
    string bestTeam;

    for (const string &t : teams)
    {
        int s = score(base, t);
        if (s > bestScore || (s == bestScore && (bestTeam.empty() || t < bestTeam)))
        {
            bestScore = s;
            bestTeam = t;
        }
    }

    cout << bestTeam << "\n";
    return 0;
}
