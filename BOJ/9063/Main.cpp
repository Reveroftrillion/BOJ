#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int min_x = 10001, max_x = -10001, min_y = 10001, max_y = -10001;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a <= min_x)
            min_x = a;
        if (a > max_x)
            max_x = a;
        if (b <= min_y)
            min_y = b;
        if (b > max_y)
            max_y = b;
    }
    cout << (max_x - min_x) * (max_y - min_y) << endl;
}