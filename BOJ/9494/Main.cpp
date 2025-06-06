#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ????

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break; // n==0 이면 종료

        cin.ignore(); // 남아 있는 개행 제거
        vector<string> text(n);
        for (int i = 0; i < n; i++)
        {
            getline(cin, text[i]);
        }

        // 1) 첫 줄(text[0])에서 첫 번째 단어의 첫 글자를 찾는다.
        int start_col = 0;
        while (start_col < (int)text[0].size() && text[0][start_col] == ' ')
            start_col++;
        // 이제 start_col 은 첫 줄에서 첫 번째 ‘공백이 아닌 문자’의 인덱스

        // 2) 시뮬레이션: 각 줄을 순회하며 가능한 한 오른쪽으로 구르다가(공백을 만날 때까지),
        //    그 지점에서 다음 줄로 떨어진다.
        int col = start_col;
        for (int row = 0; row < n; row++)
        {
            int len = (int)text[row].size();
            int c = col;
            // c < len 이고, text[row][c]가 비어 있지 않으면(=문자가 있으면)
            // 오른쪽으로 한 칸씩 이동하며 ’ ’(공백)이 나올 때까지 계속
            while (c < len && text[row][c] != ' ')
            {
                c++;
            }
            // c가 len 이상이거나 text[row][c]==' ' 인 위치가
            // 바로 “다음 줄로 공이 떨어질 열”이 된다.
            col = c;
        }

        // 최종 col 은 0-based 인덱스. 문제에서는 “첫 번째 열을 1”로 보기 때문에 +1 출력
        cout << (col + 1) << "\n";
    }

    return 0;
}
