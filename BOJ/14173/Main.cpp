#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int min_x = min(x1, x3);
    int max_x = max(x2, x4);
    int min_y = min(y1, y3);
    int max_y = max(y2, y4);

    int side = max(max_x - min_x, max_y - min_y);

    cout << side * side << endl;

    return 0;
}