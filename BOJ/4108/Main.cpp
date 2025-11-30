#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 8방향 탐색을 위한 델타 배열
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;

    while (true)
    {
        cin >> R >> C;

        // 종료 조건
        if (R == 0 && C == 0)
        {
            break;
        }

        vector<string> board(R);

        // 맵 입력
        for (int i = 0; i < R; i++)
        {
            cin >> board[i];
        }

        // 전체 맵 순회
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                // 지뢰인 경우 그대로 출력
                if (board[i][j] == '*')
                {
                    cout << '*';
                }
                // 빈 칸인 경우 주변 지뢰 개수 탐색
                else
                {
                    int count = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        // 맵 범위를 벗어나지 않고 지뢰인 경우 카운트 증가
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C)
                        {
                            if (board[nx][ny] == '*')
                            {
                                count++;
                            }
                        }
                    }
                    cout << count;
                }
            }
            cout << '\n';
        }
    }

    return 0;
}