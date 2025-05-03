#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int sum = 0;
    for (int i = 0; i <= t; i++)
    {
        sum += (i + 1);
    }
    cout << sum * t << endl;
}