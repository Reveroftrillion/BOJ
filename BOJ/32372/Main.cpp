#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> records(M);
    for (int i = 0; i < M; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        records[i] = {x, y, k};
    }

    for (int bx = 1; bx <= N; bx++)
    {
        for (int by = 1; by <= N; by++)
        {
            bool ok = true;
            for (auto &[x, y, k] : records)
            {
                if (bx == x && by == y)
                {
                    ok = false;
                    break;
                }
                switch (k)
                {
                case 1:
                    if (!(bx < x && by == y))
                        ok = false;
                    break;
                case 2:
                    if (!(bx < x && by > y))
                        ok = false;
                    break;
                case 3:
                    if (!(bx == x && by > y))
                        ok = false;
                    break;
                case 4:
                    if (!(bx > x && by > y))
                        ok = false;
                    break;
                case 5:
                    if (!(bx > x && by == y))
                        ok = false;
                    break;
                case 6:
                    if (!(bx > x && by < y))
                        ok = false;
                    break;
                case 7:
                    if (!(bx == x && by < y))
                        ok = false;
                    break;
                case 8:
                    if (!(bx < x && by < y))
                        ok = false;
                    break;
                }
                if (!ok)
                    break;
            }
            if (ok)
            {
                cout << bx << " " << by << "\n";
                return 0;
            }
        }
    }
    return 0;
}
