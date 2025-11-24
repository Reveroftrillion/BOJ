#include <bits/stdc++.h>
using namespace std;

bool rank_is_big[501][501];   // rank_is_big[i][j]면, i팀이 j팀보다 순위가 위
int how_many_team_above[501]; // 위에 몇 팀이 있는지

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        // 루프 돌 때 마다 초기화 해주기.
        memset(rank_is_big, false, sizeof(rank_is_big));
        memset(how_many_team_above, 0, sizeof(how_many_team_above));

        int n;
        cin >> n;
        vector<int> rank;
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            rank.push_back(k);
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int winner = rank[j];
                int loser = rank[k];

                rank_is_big[winner][loser] = true;
                how_many_team_above[loser]++;
            }
        }

        int m;
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;
            // a가 b보다 순위가 높음
            if (rank_is_big[a][b])
            {
                rank_is_big[a][b] = false;
                rank_is_big[b][a] = true; // 순서 바뀐 거 표시
                how_many_team_above[b]--;
                how_many_team_above[a]++;
            }
            // b가 a보다 순위가 높음
            else
            {
                rank_is_big[b][a] = false;
                rank_is_big[a][b] = true;
                how_many_team_above[a]--;
                how_many_team_above[b]++;
            }
        }

        queue<int> first_team_hubo;
        for (int j = 1; j <= n; j++)
        {
            if (how_many_team_above[j] == 0)
            {
                first_team_hubo.push(j);
            }
        }

        vector<int> this_year;
        bool impossible = false;
        bool ambiguous = false;

        for (int j = 0; j < n; j++)
        {
            if (first_team_hubo.empty())
            {
                impossible = true;
                break;
            }
            if (first_team_hubo.size() > 1)
            {
                ambiguous = true;
                break;
            }
            int current = first_team_hubo.front();
            first_team_hubo.pop();
            this_year.push_back(current);
            // 현재 1등이 빠졌으니, 1등한테 진 애들은 1씩 낮춰주기.
            for (int next = 1; next <= n; next++)
            {
                if (rank_is_big[current][next])
                {
                    how_many_team_above[next]--;
                    if (how_many_team_above[next] == 0)
                    {
                        first_team_hubo.push(next);
                    }
                }
            }
        }
        if (impossible)
        {
            cout << "IMPOSSIBLE\n";
        }
        else if (ambiguous)
        {
            cout << "?\n";
        }
        else
        {
            for (int x : this_year)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}