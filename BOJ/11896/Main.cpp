#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int a, b;
    cin >> a >> b;
    long long A = ((a + 1) / 2) * 2;
    long long B = (b / 2) * 2;
    if (A <= 2)
    {
        A = 4;
    }
    if (B < A)
    {
        cout << 0;
    }
    else
    {
        long long num = ((B - A) / 2) + 1;
        cout << num * (A + B) / 2;
    }
    return 0;
}