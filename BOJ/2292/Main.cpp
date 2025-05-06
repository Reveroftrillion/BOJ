#include <iostream>
using namespace std;

int main() // 나는 빼 가는 형식으로 만들려고 했는데, 수학적 오류가 발생. 누적시켜서 더한 다음, t보다 커질 때 while문 빠져 나오게 만듦.
{
    int t;
    cin >> t;
    int sum = 1;
    int num = 1;
    while (sum < t)
    {
        sum += 6 * num;
        num++;
    }
    cout << num << endl;
}