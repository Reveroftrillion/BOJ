#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    long long width = 0, height = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        width += a;
    }

    for (int j = 0; j < e - 1; j++)
    {
        int b;
        cin >> b;
        height += b;
    }

    double result = sqrt((double)width * width + (double)height * height);
    // ceil은 올림, floor은 버림, round는 반올림
    cout << (long long)ceil(result) << endl;

    return 0;
}