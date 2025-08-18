#include <iostream>
#include <vector>

using namespace std;

bool bad_combo[201][201] = {false};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        bad_combo[u][v] = true;
        bad_combo[v][u] = true;
    }

    int count = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            for (int k = j + 1; k <= N; ++k)
            {
                if (bad_combo[i][j] || bad_combo[j][k] || bad_combo[i][k])
                {
                    continue;
                }
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}