#include <iostream>
using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;
    int num = 1;

    while (true)
    {

        if ((num - E) % 15 == 0 && (num - S) % 28 == 0 && (num - M) % 19 == 0)
        {
            break;
        }
        else
            num++;
    }

    cout << num << "\n";
    return 0;
}