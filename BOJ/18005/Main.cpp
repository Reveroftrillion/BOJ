#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << 0 << "\n";
    }
    else
    {
        long long half_n = n / 2;
        if (half_n % 2 == 0)
        {
            cout << 2 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}