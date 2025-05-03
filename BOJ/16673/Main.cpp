#include <iostream>
using namespace std;

int main()
{
    int C;
    cin >> C;
    int sum = 0;
    int K, P;
    cin >> K >> P;
    for (int i = 1; i < C + 1; i++)
    {
        sum += K * i + P * i * i;
    }
    cout << sum << endl;
}
