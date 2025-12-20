#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Y, X;
    if (!(cin >> Y >> X)) return 0;

    vector<string> grid(Y);
    for (int i = 0; i < Y; i++) {
        cin >> grid[i];
    }

    bool found = false;
    int target_row = -1;

    // 가로가 짝수일 때와 홀수일 때를 나누어 처리합니다.
    if (X % 2 == 0) {
        int m = X / 2;
        // 테두리를 제외한 1행부터 Y-2행까지 탐색합니다.
        for (int i = 1; i < Y - 1; i++) {
            // 중심 4칸이 모두 X인지 확인합니다. (B가 아니어야 함)
            if (grid[i][m - 2] == 'X' && grid[i][m - 1] == 'X' && 
                grid[i][m] == 'X' && grid[i][m + 1] == 'X') {
                
                target_row = i;
                grid[i][m - 2] = 'W';
                grid[i][m - 1] = 'Y';
                grid[i][m] = 'Y';
                grid[i][m + 1] = 'W';
                found = true;
                break;
            }
        }
    } else {
        int m = X / 2;
        for (int i = 1; i < Y - 1; i++) {
            // 중심 3칸이 모두 X인지 확인합니다.
            if (grid[i][m - 1] == 'X' && grid[i][m] == 'X' && 
                grid[i][m + 1] == 'X') {
                
                target_row = i;
                grid[i][m - 1] = 'W';
                grid[i][m] = 'Y';
                grid[i][m + 1] = 'W';
                found = true;
                break;
            }
        }
    }

    if (found) {
        cout << "YES" << "\n";
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                // 패턴을 넣은 칸 외의 모든 X는 B로 출력하여 대칭을 맞추고 연결성을 확보합니다.
                if (grid[i][j] == 'X') cout << 'B';
                else cout << grid[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}