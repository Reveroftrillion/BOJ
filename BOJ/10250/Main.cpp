#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // c%a랑 c/a+1로 풀려니까 문제 1. c%a == 0일 때, 0층 출력 & 2. 0의 위치가 너무 고정됨

        int floor, room;
        floor = (c % a == 0) ? a : c % a; // 나머지가 0일 때, 맨 위층에 배정되니 삼중 연산자로 0인 경우 해결
        room = (c - 1) / a + 1;           // 맨 위층을 나머지가 0일 때, 배정하니 1을 빼준다.

        cout << floor * 100 + room << endl;
    }
}