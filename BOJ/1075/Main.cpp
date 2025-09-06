#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, F;
    cin >> N >> F;

    int temp_N = (N / 100) * 100;

    for (int i = 0; i < 100; ++i)
    {
        if ((temp_N + i) % F == 0)
        {
            cout << setw(2) << setfill('0') << i << endl;
            break;
        }
    }

    return 0;
}