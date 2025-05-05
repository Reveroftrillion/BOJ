#include <iostream>
using namespace std;

int main()
{
    int array1[101][101];
    int array2[101][101];

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> array1[i][j];
        }
    }

    for (int k = 0; k < a; k++)
    {
        for (int l = 0; l < b; l++)
        {
            cin >> array2[k][l];
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << array1[i][j] + array2[i][j] << ' ';
        }
        cout << endl;
    }
}