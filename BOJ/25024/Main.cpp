#include <iostream>
using namespace std;

string time(int a, int b)
{
    if (0 <= a && a <= 23)
    {
        if (0 <= b && b <= 59)
        {
            return "Yes";
        }
        return "No";
    }
    else
    {
        return "No";
    }
}

string year(int a, int b)
{
    if (a == 2)
    {
        if (1 <= b && b <= 29)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    else if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
    {
        if (1 <= b && b <= 31)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    else if (a == 4 || a == 6 || a == 9 || a == 11)
    {
        if (1 <= b && b <= 30)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    else
    {
        return "No";
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int p, q;
        cin >> p >> q;
        cout << time(p, q) << " " << year(p, q) << endl;
    }
}