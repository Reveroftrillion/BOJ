#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> digits;
    for (char c : str)
    {
        digits.push_back(c - '0');
    }
    sort(digits.begin(), digits.end());
    reverse(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); i++)
    {
        cout << digits[i];
    }
}