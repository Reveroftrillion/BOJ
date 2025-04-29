#include <iostream>
using namespace std;

int main()
{
    for (int i = 0;; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            break;
        }
        cout << a + b << endl;
    }
}