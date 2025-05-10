#include <iostream>
#include <algorithm>
using namespace std;

int apartment(int a, int b)
{
    int array[15][15] = {};
    for (int i = 0; i < 15; i++)
    {
        array[0][i] = i + 1;
    }
    for (int j = 1; j < 15; j++)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int k = 0; k <= i; k++)
                array[j][i] += array[j - 1][k];
        }
    }
    return array[a][b - 1]; // 내가 만든 배열은 0층 0호부터 시작, 문제는 0층 1호부터 시작
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k, n;
        cin >> k >> n;
        cout << apartment(k, n) << endl;
    }
}