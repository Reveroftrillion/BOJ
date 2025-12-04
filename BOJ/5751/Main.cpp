#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;

        int mary = 0, john = 0;
        for (int i = 0; i < N; i++)
        {
            int r;
            cin >> r;
            if (r == 0)
                mary++;
            else
                john++;
        }

        cout << "Mary won " << mary << " times and John won " << john << " times\n";
    }

    return 0;
}
