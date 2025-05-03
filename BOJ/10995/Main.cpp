#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < t; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < t; j++)
            {
                cout << " *";
            }
            cout << endl;
        }
    }
}