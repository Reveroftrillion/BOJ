#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int answer1 = (-a) - sqrt(a * a - b);
    int answer2 = (-a) + sqrt(a * a - b);
    if (answer1 == answer2)
    {
        cout << answer1 << endl;
    }
    else
    {
        cout << answer1 << " " << answer2 << endl;
    }
}