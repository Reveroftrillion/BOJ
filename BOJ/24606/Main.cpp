#include <iostream>
using namespace std;

int main()
{
    string p, q;
    cin >> p >> q;
    int k = 1;
    for (int i = 0; i < 4; i++)
    {
        if (p[i] != q[i])
        {
            k *= 2;
        }
    }
    cout << k << endl;
}