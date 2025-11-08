#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<string> S;
    S.reserve(1000000);
    S.max_load_factor(0.7f);

    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;
        size_t pos = line.find(' ');
        if (pos == string::npos)
            continue;
        string name = line.substr(pos + 1);
        if (!name.empty() && name.back() == '\r')
            name.pop_back();
        S.insert(std::move(name));
    }

    cout << S.size() << '\n';
    return 0;
}
