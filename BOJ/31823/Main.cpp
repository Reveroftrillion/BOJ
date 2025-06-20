#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    vector<int> stric(a);
    vector<string> name(a);
    set<int> answer;

    for (int i = 0; i < a; i++)
    {
        int cur = 0, longest = 0;
        for (int j = 0; j < b; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
            {
                cur++;
                longest = max(longest, cur);
            }
            if (c == '*')
            {
                cur = 0;
            }
        }

        string str;
        cin >> str;

        name[i] = str;
        stric[i] = longest;
        answer.insert(longest);
    }

    cout << answer.size() << endl;

    for (int i = 0; i < a; i++)
    {
        cout << stric[i] << " " << name[i] << endl;
    }
}