#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, T;
    cin >> A >> B >> C >> T;

    if (T <= 30)
    {
        cout << A << '\n';
    }
    else
    {
        int over = T - 30;
        int blocks = (over + B - 1) / B;
        cout << A + blocks * C << '\n';
    }
    return 0;
}
