#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H;
    cin >> H;

    string path;
    if (!(cin >> path))
        path = "";

    long long height = (1LL << (H + 1)) - 1;
    long long idx = 1;

    for (char c : path)
    {
        if (c == 'L')
            idx = idx * 2;
        else
            idx = idx * 2 + 1;
    }

    long long label = height - idx + 1;
    cout << label << "\n";
    return 0;
}
