#include <iostream>
using namespace std;

int main()
{
    int data, month;
    cin >> data >> month;
    int sum = data;
    for (int i = 0; i < month; i++)
    {
        int used;
        cin >> used;
        sum += (data - used);
    }
    cout << sum << endl;
}