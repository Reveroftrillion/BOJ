#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int array[101];
    for (int i = 0; i <= a; i++)
    {
        array[i] = i;
    }
    int p, q;
    for (int i = 0; i < b; i++)
    {
        cin >> p >> q;
        int r = array[p];
        array[p] = array[q];
        array[q] = r;
    }

    for (int i = 1; i <= a; i++)
    {
        cout << array[i] << '\n';
    }
}