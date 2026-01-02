#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 최대공약수 계산 함수
// C++17 이상에서는 <numeric> 헤더의 std::gcd를 사용 가능하지만
// 버전에 상관없이 동작하도록 간단히 구현해 두어도 좋습니다
int get_gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // 입력이 없을 때까지 반복
    while (cin >> n) {
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        // 가장 큰 수를 찾아야 하므로 내림차순 정렬
        sort(numbers.begin(), numbers.end(), greater<int>());

        int answer = -1;

        // 큰 수부터 차례대로 검사
        for (int i = 0; i < n; i++) {
            bool is_winner = true;
            
            // 다른 모든 수와의 관계 확인
            for (int j = 0; j < n; j++) {
                if (i == j) continue; // 자기 자신은 제외
                
                // 공약수가 1보다 크면 서로소가 아님
                if (get_gcd(numbers[i], numbers[j]) > 1) {
                    is_winner = false;
                    break;
                }
            }

            // 모든 수와 서로소라면 이 수가 정답
            if (is_winner) {
                answer = numbers[i];
                break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}