#include <iostream>
using namespace std;

// 원래 팩토리얼로 잘 짜놨는데, 오버플로우 발생해서 새로운 함수 사용.
// 분모에 가장 위에서 부터 n개 곱한걸 분자에서 가장 작은 수 부터 n개 곱한거로 나눈것과 동일.

long long bridge(int a, int b)
{
    long long result = 1;
    for (int i = 1; i <= b; i++)
    {
        result *= (a - i + 1);
        result /= i; // 위에는 곱해주고 밑에서 바로 나눠줌 = 오버플로우 발생 X
    }
    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int N, M;
        cin >> N >> M;
        cout << bridge(M, N) << endl;
    }
}