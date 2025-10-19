#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    string result = "";
    for (int i = 0; i < m; i++)
    {
        vector<int> count(26, 0);
        for (int j = 0; j < n; j++)
        {
            count[names[j][i] - 'a']++;
        }
        int max_count = *max_element(count.begin(), count.end());
        for (int k = 0; k < 26; k++)
        {
            if (count[k] == max_count)
            {
                result += char('a' + k);
                break;
            }
        }
    }

    cout << result << endl;
    return 0;
}
