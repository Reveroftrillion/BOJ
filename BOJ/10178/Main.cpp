#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << "You get " << a / b << " piece(s) and your dad gets " << a % b << " piece(s)." << endl;
    }
}