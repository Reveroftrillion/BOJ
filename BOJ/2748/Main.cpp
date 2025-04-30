#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int a)
{
    vector<long long> vec(91);
    vec[0] = 0;
    vec[1] = 1;
    for (int i = 2; i <= 90; i++)
    {
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    return vec[a];
}

int main()
{
    int t;
    cin >> t;
    long long fibo = fibonacci(t);
    cout << fibo << endl;
}