#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> dist(N, -1); // 방문 여부 + 점프 횟수 저장
    queue<int> q;
    q.push(0);      // 시작점 (1번 칸, 인덱스 0)
    dist[0] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 현재 위치에서 점프 가능한 범위
        for (int jump = 1; jump <= A[cur]; jump++) {
            int next = cur + jump;
            if (next >= N) break;     // 범위 초과
            if (dist[next] != -1) continue; // 이미 방문

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << dist[N - 1] << endl;
}
