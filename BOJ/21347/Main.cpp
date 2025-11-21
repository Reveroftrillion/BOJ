#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    int i = 0, j = 0;
    int n = s.size(), m = t.size();
    vector<char> order;
    vector<bool> seen(256, false);
    while (i < n)
    {
        char c = s[i];
        int ks = 0;
        while (i < n && s[i] == c)
        {
            ks++;
            i++;
        }

        int kt = 0;
        while (j < m && t[j] == c)
        {
            kt++;
            j++;
        }

        if (kt == 2 * ks)
        {
            if (!seen[(unsigned char)c])
            {
                order.push_back(c);
                seen[(unsigned char)c] = true;
            }
        }
    }

    for (char c : order)
        cout << c;
    cout << '\n';
    return 0;
}
