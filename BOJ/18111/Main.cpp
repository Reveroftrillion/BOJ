#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long B;
    cin >> N >> M >> B;

    vector<int> land(N * M);
    for (int i = 0; i < N * M; i++)
    {
        cin >> land[i];
    }

    long long bestTime = LLONG_MAX;
    int bestHeight = 0;

    for (int h = 0; h <= 256; h++)
    {
        long long remove = 0;
        long long build = 0;

        for (int x : land)
        {
            if (x > h)
                remove += (x - h);
            else if (x < h)
                build += (h - x);
        }

        if (B + remove < build)
            continue;

        long long time = remove * 2 + build;

        if (time < bestTime || (time == bestTime && h > bestHeight))
        {
            bestTime = time;
            bestHeight = h;
        }
    }

    cout << bestTime << " " << bestHeight << "\n";
    return 0;
}
