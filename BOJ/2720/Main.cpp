#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int money;
        int quarter, dime, nickel, penny;
        cin >> money;
        quarter = money / 25;
        money %= 25;
        dime = money / 10;
        money %= 10;
        nickel = money / 5;
        money %= 5;
        penny = money;
        cout << quarter << " " << dime << " " << nickel << " " << penny << '\n';
    }
}