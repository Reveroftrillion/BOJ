#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> numbers(N);
    double sum = 0.0;

    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
        sum += numbers[i];
    }

    double mean = sum / N;

    sort(numbers.begin(), numbers.end());

    double median;
    if (N % 2 != 0)
    {
        median = numbers[N / 2];
    }
    else
    {
        median = (numbers[N / 2 - 1] + numbers[N / 2]) / 2.0;
    }

    cout << fixed << setprecision(6);
    cout << mean << endl;
    cout << median << endl;

    return 0;
}