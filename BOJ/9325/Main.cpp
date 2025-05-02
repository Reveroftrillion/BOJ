#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int sum = 0;
        int car;
        cin >> car;
        sum += car;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int number, option;
            cin >> number >> option;
            int K = number * option;
            sum += K;
        }
        cout << sum << endl;
    }
}