#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    string vote;
    cin >> vote;
    int vote_for_A = 0;
    int vote_for_B = 0;
    for (int i = 0; i < a; i++)
    {
        if (vote[i] == 'A')
        { // "A"는 const char이고, vote[i]는 char이라서 다른 타입이다.
            vote_for_A += 1;
        }
        else
        {
            vote_for_B += 1;
        }
    }
    if (vote_for_A > vote_for_B)
    {
        cout << "A" << endl;
    }
    else if (vote_for_A < vote_for_B)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "Tie" << endl;
    }
}
