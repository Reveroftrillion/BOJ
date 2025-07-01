#include <iostream>
using namespace std;

long long g(int k)
{
    long long num = 0;
    for (int i = 1; i <= k; ++i)
    {
        num += 1LL * i * (k / i); // 10까지 구할 때, 1은 10번, 2는 5번, 3은 3번 등장하는 것을 활용
                                  // 여기서 1LL곱해주는건 이걸 long long 식으로 쓰려고
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    cout << g(n) << endl;
}