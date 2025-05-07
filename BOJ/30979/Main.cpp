#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        t -= a;
    }
    if (t > 0)
    {
        cout << "Padaeng_i Cry" << endl;
    }
    else
    {
        cout << "Padaeng_i Happy" << endl;
    }
}