#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> str;
    string answer;
    for (int i = 0; i < 5; i++)
    {
        string st;
        cin >> st;
        str.push_back(st);
    }
    for (int k = 0; k < 15; k++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (k < str[j].size())
                answer += str[j][k];
        }
    }
    cout << answer << '\n';
}