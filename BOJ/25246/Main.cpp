#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s))
        return 0;

    string vowels = "aeiou";
    int pos = -1;
    for (int i = (int)s.size() - 1; i >= 0; --i)
    {
        if (vowels.find(s[i]) != string::npos)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        cout << s << "ntry\n";
    }
    else
    {
        cout << s.substr(0, pos + 1) << "ntry\n";
    }

    return 0;
}
