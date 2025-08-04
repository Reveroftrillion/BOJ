#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> d;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        d.push_back(t);
    }
    sort(d.begin(), d.end(), greater<int>());
    int doughCal = C / A;
    int bestCal = doughCal;
    int totalPrice = A;
    int totalCal = C;
    for (int i = 0; i < N; i++)
    {
        totalPrice += B;
        totalCal += d[i];
        if (bestCal < totalCal / totalPrice)
        {
            bestCal = totalCal / totalPrice;
        }
    }

    cout << bestCal;
}