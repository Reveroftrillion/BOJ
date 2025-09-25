#include <iostream>
using namespace std;

int main()
{
    int T, N, M;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        if (N < 12 || M < 4)
            cout << -1 << '\n';
        else
            cout << (M * 11 + 4) << '\n';
    }
    return 0;
}
