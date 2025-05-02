#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int l = 1; l < t; l++)
    {
        for (int m = 0; m < l; m++)
        {
            cout << " ";
        }
        for (int n = 0; n < 2 * t - 2 * l - 1; n++)
        {
            cout << "*";
        }
        cout << endl;
    }
}