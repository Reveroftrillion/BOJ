#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int shinParity = -1; // 주인공의 행+열 합의 홀짝성 (0 또는 1)
    vector<pair<int, int>> legions; // 레기온들의 위치 저장

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int type;
            cin >> type;
            
            if (type == 2) {
                // 주인공 위치 파악: 행과 열의 합을 2로 나눈 나머지 저장
                shinParity = (i + j) % 2;
            } else if (type == 1) {
                // 레기온 위치 저장
                legions.push_back({i, j});
            }
        }
    }

    bool possible = true;

    // 모든 레기온에 대해 검사
    for (const auto& legion : legions) {
        int r = legion.first;
        int c = legion.second;
        
        // 레기온의 행+열 합의 홀짝성 계산
        int legionParity = (r + c) % 2;

        // 주인공과 레기온의 홀짝성이 같다면 처치 불가능
        if (shinParity == legionParity) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "Lena";
    } else {
        cout << "Kiriya";
    }

    return 0;
}