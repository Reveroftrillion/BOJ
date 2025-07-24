#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int maxNumber = 0, minNumber = 1000000000;
    vector<int> marble(N);
    for (int i = 0; i < N; i++)
    {
        cin >> marble[i];
        maxNumber = max(maxNumber, marble[i]);
        minNumber = min(minNumber, marble[i]);
    }
    cout << 2 * (maxNumber - minNumber) << endl;
}