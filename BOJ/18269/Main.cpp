#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    cin >> n >> str;

    for (int k = 1; k <= n; k++)
    {
        bool OK = true;
        for (int i = 0; i <= n - k; i++)
        {
            string tmp = str.substr(i, k);
            for (int j = 0; j <= n - k; j++)
            {
                if (i == j)
                    continue;
                if (tmp == str.substr(j, k))
                    OK = false;
            }
        }
        if (OK)
        {
            cout << k << '\n';
            return 0;
        }
    }
    return 0;
}