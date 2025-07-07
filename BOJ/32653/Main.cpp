#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> ap;
    for (int i = 0; i < N; i++)
    {
        long long k;
        cin >> k;
        ap.push_back(k);
    }

    long long result = ap[0];
    for (size_t i = 1; i < ap.size(); i++)
    {
        result = lcm(result, ap[i]);
    }

    cout << result * 2 << endl; // 앞 뒤 구워주니까 2를 곱해준다.
}