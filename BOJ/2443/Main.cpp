#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int k = 0; k < i; k++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * t - 1 - 2 * i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}