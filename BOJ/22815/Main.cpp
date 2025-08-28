#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int cave = 0; cave < N; cave++)
    {
        int dx, dy;
        int x = 0, y = 0;
        int bestX = 0, bestY = 0;
        long long maxDist = 0;

        while (true)
        {
            cin >> dx >> dy;
            if (dx == 0 && dy == 0)
                break;

            x += dx;
            y += dy;

            long long dist = 1LL * x * x + 1LL * y * y;
            if (dist > maxDist || (dist == maxDist && x > bestX))
            {
                maxDist = dist;
                bestX = x;
                bestY = y;
            }
        }

        cout << bestX << " " << bestY << "\n";
    }

    return 0;
}
