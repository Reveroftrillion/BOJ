#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int cute = 0;
    int ncute = 0;
    for (int i = 0; i < t; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            cute++;
        }
        else
        {
            ncute++;
        }
    }
    if (cute > ncute)
    {
        cout << "Junhee is cute!" << endl;
    }
    else
    {
        cout << "Junhee is not cute!" << endl;
    }
}