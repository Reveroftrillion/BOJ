#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int m, seed, x1, x2;
    int a = 0, c = 0, temp;
    cin >> m >> seed >> x1 >> x2;
    for (a = 0; a < m; a++)
    {
        for (c = 0; c < m; c++)
        {
            if ((a * seed + c) % m == x1)
            {
                if ((a * x1 + c) % m == x2)
                {
                    cout << a << " " << c;
                    return 0;
                }
            }
        }
    }
}