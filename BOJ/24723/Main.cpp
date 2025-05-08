#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int result = 1;

    for (int i = 0; i < t; i++)
    {
        result *= 2;
    }

    cout << result << endl;
}