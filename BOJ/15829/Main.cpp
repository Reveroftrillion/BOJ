#include <iostream>
using namespace std;

int main()
{
    int t;
    string str;
    cin >> t >> str;

    long long H = 0;
    long long r = 1;
    long long M = 1234567891;

    for (int i = 0; i < t; i++)
    {
        int a = str[i] - 'a' + 1;
        H = (H + a * r) % M; // 해시 값 = 그 전까지의 해시 값들의 합 + 문자들을 숫자로 나타낸 값 * 31의 0승부터 쭉 더하고 M으로 나눈 나머지
        r = (r * 31) % M;
    }
    cout << H << endl;
}