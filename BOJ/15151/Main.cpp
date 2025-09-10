#include <iostream>
using namespace std;

int main()
{
    long long k, d;
    cin >> k >> d;

    int count = 0;
    long long current_days = k;

    while (d >= current_days)
    {
        d -= current_days;
        count++;
        current_days *= 2;
    }

    cout << count << endl;

    return 0;
}