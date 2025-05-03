#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int elec = 0;
    cin >> elec;
    for (int i = 0; i < t - 1; i++)
    {
        int k;
        cin >> k;
        elec += (k - 1);
    }
    cout << elec << endl;
}