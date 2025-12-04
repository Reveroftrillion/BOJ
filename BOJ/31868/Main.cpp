#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;

    long long need = 1LL << (N - 1);

    cout << (K / need) << endl;
    return 0;
}