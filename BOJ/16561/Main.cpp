#include <iostream>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    long long cnt;
    cnt = t / 3; // cnt만큼의 1이 3개의 덩어리로 쪼개는 거니까 cnt-1 C 2의 경우의 수 발생
    cnt = (cnt - 1) * (cnt - 2) / 2;
    cout << cnt << endl;
}