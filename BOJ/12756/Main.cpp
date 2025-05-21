#include <iostream>
using namespace std;

int main()
{
    int a_attack, a_life, b_attack, b_life;
    cin >> a_attack >> a_life >> b_attack >> b_life;
    int a_count = 0;
    int b_count = 0;
    while (a_life > 0)
    {
        a_life -= b_attack;
        a_count++;
    }
    while (b_life > 0)
    {
        b_life -= a_attack;
        b_count++;
    }
    if (a_count > b_count)
    {
        cout << "PLAYER A" << endl;
    }
    else if (a_count < b_count)
    {
        cout << "PLAYER B" << endl;
    }
    else if (a_count = b_count)
    {
        cout << "DRAW" << endl;
    }
}