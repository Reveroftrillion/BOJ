#include <iostream>
using namespace std;

int Max_num(int a, int b)
{
    int k = min(a, b);
    int m = 0;
    for (int i = 1; i < k + 1; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            m = i;
        }
    }
    return m;
}

int Min_num(int a, int b)
{
    int k = min(a, b);
    int m = 0;
    for (int i = 1; i < k + 1; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            m = i;
        }
    }
    int K = m * (a / m) * (b / m);
    return K;
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << Max_num(A, B) << endl;
    cout << Min_num(A, B) << endl;
}