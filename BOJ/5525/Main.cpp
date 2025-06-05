#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    string str;
    cin >> n >> m >> str;

    int i = 0, count = 0, result = 0;

    while (i < m - 1)
    {
        if (str[i] == 'I')
        {
            count = 0;
            while (i + 2 < m && str[i + 1] == 'O' && str[i + 2] == 'I')
            {
                count++;
                i += 2;
                if (count == n)
                {
                    result++;
                    count--; // 겹치는 경우 처리
                }
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    cout << result << '\n';
}
