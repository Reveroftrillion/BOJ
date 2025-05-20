#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector<bool> eratostenes(b + 1, true);
    eratostenes[0] = eratostenes[1] = false;

    for (int i = 2; i * i <= b; i++)
    {
        if (eratostenes[i])
        {
            for (int j = i * i; j <= b; j += i)
            {
                eratostenes[j] = false;
            }
        }
    }

    for (int k = a; k <= b; k++)
    {
        if (eratostenes[k])
        {
            cout << k << '\n';
        }
    }

    return 0;
}