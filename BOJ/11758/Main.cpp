#include <iostream>
using namespace std;

// 벡터의 외적. 1에서 2로 가는 것과 1에서 3으로 가는 걸 기준삼아 방향 측정
// 양수면 시계방향, 음수면 반시계방향이다.

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int result = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}
int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << ccw(a, b, c, d, e, f) << '\n';
}
