#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;

    int qtr = 0, half = 0, tqtr = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "1/4")
            qtr++;
        else if (s == "1/2")
            half++;
        else if (s == "3/4")
            tqtr++;
    }

    int pizzas = tqtr;
    qtr = max(0, qtr - tqtr);

    pizzas += half / 2;
    half %= 2;

    if (half == 1)
    {
        pizzas += 1;
        qtr -= min(qtr, 2);
    }

    if (qtr > 0)
    {
        pizzas += (qtr + 3) / 4;
    }

    cout << pizzas << '\n';
    return 0;
}
