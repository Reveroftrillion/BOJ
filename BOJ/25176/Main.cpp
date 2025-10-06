#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int num = 1;
    for (int i = 1; i <= N; i++)
    {
        num *= i;
    }
    cout << num;

    return 0;
}