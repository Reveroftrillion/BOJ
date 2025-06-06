#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string str;
    cin >> k >> str;
    vector<string> code;
    int num = 0;
    for (int i = 0; i < str.size(); i += k)
    {
        string part = str.substr(i, k);
        if (num % 2 == 1)
        {
            reverse(part.begin(), part.end());
        }
        code.push_back(part);
        num++;
    }
    for (int col = 0; col < k; col++)
    {
        for (int row = 0; row < code.size(); row++)
        {
            cout << code[row][col];
        }
    }
    cout << '\n';

    return 0;
}