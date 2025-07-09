#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 처음에 set써서 풀려고 했는데, 이러면 단방향 감염만 적용돼서 안된다.
// 이건 BFS써서 풀어야 한다.

int main()
{
    int computer, pair;
    cin >> computer >> pair;

    // 2차원 동적 배열
    // 1번부터 computer까지.
    vector<vector<int>> graph(computer + 1);
    vector<bool> visited(computer + 1, false);

    for (int i = 0; i < pair; i++)
    {
        int u, v;
        cin >> u >> v;
        // 양방향으로 연결 정보를 저장해준다.
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 여기부터 BFS 시작.
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int answer = 0;

    while (!q.empty())
    {
        // 1부터 시작 -> graph에 입력된 값들을 확인
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
