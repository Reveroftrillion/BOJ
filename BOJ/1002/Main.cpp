#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int x1, y1, r1, x2, y2, r2, new_circle, small_circle, big_circle;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        new_circle = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        small_circle = (r1 - r2) * (r1 - r2);
        big_circle = (r1 + r2) * (r1 + r2);

        if (new_circle == 0)
        {
            if (small_circle == 0)
                cout << "-1" << '\n';
            else
                cout << "0" << '\n';
        }

        else if (new_circle == small_circle || new_circle == big_circle)
            cout << "1" << '\n';

        else if (small_circle < new_circle && new_circle < big_circle)
            cout << "2" << '\n';

        else
            cout << "0" << '\n';
    }
}