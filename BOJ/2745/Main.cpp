#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    int t;
    cin >> str >> t;
    reverse(str.begin(), str.end());
    long long num = 1;
    long long sum = 0;
    for (char c : str)
    {
        int k;
        if ('0' <= c && c <= '9')
        {
            k = c - '0';
        }
        else
        {
            k = c - 'A' + 10;
        }
        sum += num * k;
        num *= t;
    }
    cout << sum << endl;
}