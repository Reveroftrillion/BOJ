#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    if (N != M)
    {
        int a;
        a = min(N, M);
        cout << pow(a - 1, 2) << endl;
    }
    else
    {
        int b;
        b = pow(N - 2, 2) + 1;
        cout << b << endl;
    }
}