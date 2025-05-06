#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c;
    if (a >= b)
    {
        c = a - b;
    }
    else
    {
        c = b - a;
    }
    int fact1 = 1, fact2 = 1, fact3 = 1;
    for (int i = 1; i < a + 1; i++)
    {
        fact1 *= i;
    }
    for (int i = 1; i < b + 1; i++)
    {
        fact2 *= i;
    }
    for (int i = 1; i < c + 1; i++)
    {
        fact3 *= i;
    }
    int fact4 = fact2 * fact3;
    cout << fact1 / fact4 << endl;
}