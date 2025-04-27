#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int max = 0;
    for (int i = 0; i < a; i++)
    {
        int num1, num2, num3;
        cin >> num1 >> num2 >> num3;
        int look = 0;
        if (num1 == num2 && num2 == num3) // 처음에 짤 때, num1 == num2 == num3으로 짰는데, 이건 적용 불가, 두 개로 나눠서 짜야함함
        {
            look = 10000 + num1 * 1000;
            if (look > max)
            {
                max = look;
            }
        }
        else if (num1 == num2)
        {
            look = 1000 + num1 * 100;
            if (look > max)
            {
                max = look;
            }
        }
        else if (num2 == num3)
        {
            look = 1000 + num2 * 100;
            if (look > max)
            {
                max = look;
            }
        }
        else if (num1 == num3)
        {
            look = 1000 + num1 * 100;
            if (look > max)
            {
                max = look;
            }
        }
        else if (num1 > num3 && num1 > num2)
        {
            look = num1 * 100;
            if (look > max)
            {
                max = look;
            }
        }
        else if (num2 > num3 && num2 > num1)
        {
            look = num2 * 100;
            if (look > max)
            {
                max = look;
            }
        }
        else
        {
            look = num3 * 100;
            if (look > max)
            {
                max = look;
            }
        }
    }
    cout << max << endl;
}