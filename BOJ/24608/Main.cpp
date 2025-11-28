#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    long long sum = 0;
    for (unsigned char c : s)
        sum += c;
    int avg = sum / (int)s.size();
    cout << (char)avg << '\n';
    return 0;
}
