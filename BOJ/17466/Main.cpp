#include <iostream>
using namespace std;

int main()
{
    long long N, P;
    cin >> N >> P;

    long long result = 1;

    for (long long i = 2; i <= N; ++i)
    {
        result = (result * i) % P;
    }

    cout << result << endl;
    return 0;
}
