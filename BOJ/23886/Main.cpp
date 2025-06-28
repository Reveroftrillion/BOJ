#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    if (!(cin >> str))
        return 0;

    vector<int> alps;
    for (char c : str)
        alps.push_back(c - '0');

    if (alps.size() < 2)
    {
        cout << "NON ALPSOO\n";
        return 0;
    }

    vector<int> alpsoo;
    for (size_t i = 0; i + 1 < alps.size(); ++i)
        alpsoo.push_back(alps[i] - alps[i + 1]);

    if (alpsoo[0] >= 0 || alpsoo.back() <= 0)
    {
        cout << "NON ALPSOO\n";
        return 0;
    }

    for (int d : alpsoo)
    {
        if (d == 0)
        {
            cout << "NON ALPSOO\n";
            return 0;
        }
    }

    int checking_num = alpsoo[0];
    bool alp = true;

    for (size_t i = 1; i < alpsoo.size(); ++i)
    {
        int cur = alpsoo[i];

        if ((checking_num > 0 && cur > 0) || (checking_num < 0 && cur < 0))
        {
            if (cur != checking_num)
            {
                alp = false;
                break;
            }
        }
        else
        {
            checking_num = cur;
        }
    }

    cout << (alp ? "ALPSOO\n" : "NON ALPSOO\n");
    return 0;
}
