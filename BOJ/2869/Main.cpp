#include <iostream>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long num = 1;

    c -= a;
    if (c > 0)
    {
        num += c / (a - b);
        if (c % (a - b) != 0)
        {
            num++; // 나머지가 있다면 한 번 더 반복해야 하니까
        }
    }
    cout << num << endl;

    return 0;
    /*while(c >= 0){
        c -= a;
        if (c <= 0){
            cout << num << endl;
            return 0;
        }
        c += b;
        num++;
    } 원래 while문 가지고 짰는데, 시간 초과 떠서 아예 식으로 계산하는 방법을 사용 */
}
