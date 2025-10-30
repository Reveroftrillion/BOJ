#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K))
        return 0;

    const string str = "AKARAKA";
    if (K == 1)
    {
        cout << str << '\n';
        return 0;
    }
    cout << str;
    string tail = "RAKA";
    for (int i = 1; i < K; i++)
        cout << tail;
    cout << '\n';
    return 0;
}
