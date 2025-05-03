#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        int num = 0;
        for (int i = 1; i < a + 1; i++)
        {
            if (a % i == 0)
            {
                num++;
            }
        }
        if (num == 2)
        {
            sum++;
        }
    }
    cout << sum << endl;
}