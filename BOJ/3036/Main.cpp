#include <iostream>
using namespace std;

int N;
int ring[101];

int GCD(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ring[i];
    }
    int k;
    k = ring[0];
    for (int i = 1; i < N; i++)
    {
        int g = GCD(k, ring[i]);
        cout << k / g << '/' << ring[i] / g << endl;
    }
}