#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    char chess[a][b];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            char c;
            cin >> c;
            chess[i][j] = c;
        }
    }
    int answer = 65;
    for (int i = 0; i <= a - 8; i++)
    {
        for (int j = 0; j <= b - 8; j++)
        {
            int white = 0, black = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    bool even = ((k + l) % 2 == 0); // 첫 번째 칸과 같은 색을 칠하는 쪽이 짝수로 생각
                    // 판별 결과가 true인 애들 (여기선 짝수)을 시작 칸과 같은 색으로 생각
                    if (even)
                    {
                        if (chess[k][l] != 'W')
                            white++;
                        if (chess[k][l] != 'B')
                            black++;
                    }
                    else
                    {
                        if (chess[k][l] != 'B')
                            white++;
                        if (chess[k][l] != 'W')
                            black++;
                    }
                }
            }
            int grey = min(black, white);
            answer = min(grey, answer);
        }
    }
    cout << answer << endl;
}