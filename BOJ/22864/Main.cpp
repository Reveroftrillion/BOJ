#include <iostream>
using namespace std;

int main()
{
    int A, B, C, M;
    cin >> A >> B >> C >> M;
    int work = 0;
    int pirodo = 0;
    for (int i = 1; i <= 24; i++)
    {
        if (pirodo + A <= M)
        {
            work += B;
            pirodo += A;
        }
        else
        {
            pirodo -= C;
            if (pirodo < 0)
            {
                pirodo = 0;
            }
        }
    }
    cout << work << endl;
}