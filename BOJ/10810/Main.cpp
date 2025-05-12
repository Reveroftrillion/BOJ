#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int array[101] = {0};
    int p, q, r;
    for (int i = 0; i < b; i++)
    {
        cin >> p >> q >> r;
        for (int j = p; j <= q; j++)
        {
            array[j] = r;
        }
    }

    for (int i = 1; i <= a; i++)
    {
        cout << array[i] << '\n';
    }
}