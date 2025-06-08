#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    int array1[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            int k;
            cin >> k;
            array1[i][j] = k;
        }
    }

    cin >> c >> d;
    int array2[c][d];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int k;
            cin >> k;
            array2[i][j] = k;
        }
    }

    int result[a][d];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int l = 0;
            for (int k = 0; k < b; k++)
            {
                l += array1[i][k] * array2[k][j];
            }
            result[i][j] = l;
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}