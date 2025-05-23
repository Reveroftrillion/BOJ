#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, int a, int b, vector<vector<int>> &baechu)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    if (x < 0 || x >= a || y < 0 || y >= b)
        return; // 함수 그냥 범위 밖이면 종료 시키기.

    if (baechu[x][y] == 0)
        return; // 0인 부분도 종료 시키기

    baechu[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        dfs(x + dx[i], y + dy[i], a, b, baechu);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        // 2D 배열에서 벡터 사용하려면 이런 식으로 써야 한다.
        vector<vector<int>> baechu(a, vector<int>(b, 0));
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int p, q;
            cin >> p >> q;
            baechu[p][q] = 1;
        }
        int count = 0;

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (baechu[i][j] == 1)
                {
                    dfs(i, j, a, b, baechu);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}