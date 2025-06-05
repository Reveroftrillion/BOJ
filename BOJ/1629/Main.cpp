#include <bits/stdc++.h>
using namespace std;

long long powmod(long long a, long long b, long long c)
{
    if (b == 0)
        return 1;
    long long half = powmod(a, b / 2, c); // 절반 나눠서 또 호출 = 재귀적인 방법
    long long result = (half * half) % c; // 절반 결과를 제곱하고, % c로 나머지를 구함
    if (b % 2 == 1)                       // 홀수면 한 번 더 곱해줘야 함 5 = 2 ^ 2 + 1 이니까
        result = (result * a) % c;
    return result;
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << powmod(a, b, c) << '\n';
}
