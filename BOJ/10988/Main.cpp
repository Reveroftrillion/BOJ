#include <iostream>
using namespace std;

int main()
{
    string c;
    cin >> c;
    int d;
    d = c.size();
    bool pelindulum = true;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == c[d - i - 1])
        { // d-i로만 쓰면 범위 벗어나니까 d-i-1해줘야 한다.
            pelindulum = true;
        }
        else
        {
            pelindulum = false;
            break;
        }
    }
    if (pelindulum == true)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}