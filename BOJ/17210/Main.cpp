#include <iostream>
using namespace std;

int main()
{
    int cases;
    char first;
    cin >> cases >> first;
    if (cases >= 6)
    {
        cout << "Love is open door" << endl;
    }
    else
    {
        if (first == '1')
        {
            for (int i = 0; i < cases - 1; i++)
            {
                if (i % 2 == 0)
                {
                    cout << "0" << endl;
                }
                else
                {
                    cout << "1" << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < cases - 1; i++)
            {
                if (i % 2 == 0)
                {
                    cout << "1" << endl;
                }
                else
                {
                    cout << "0" << endl;
                }
            }
        }
    }
}