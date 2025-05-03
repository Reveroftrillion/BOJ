#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            int real;
            cin >> real;
            sum += real;
        }
        cout << sum << endl;
    }
}