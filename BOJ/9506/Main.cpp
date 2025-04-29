#include <iostream>
#include <vector>
using namespace std;

vector<int> yaksu(int a)
{ // 파이썬 list처럼 쓰기 좋은 건 vector이다. append는 push_back 쓰면 되고
  // 꺼낼 때는 cout 쓰면 된다.
    vector<int> y;
    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            y.push_back(i);
        }
    }
    return y;
}

int main()
{
    while (true)
    {
        int a;
        cin >> a;
        if (a == -1)
        {
            break;
        }
        vector<int> sum = yaksu(a);
        int hap = 0;
        for (int j = 0; j < sum.size(); j++)
        {
            hap += sum[j];
        }
        if (a == hap)
        {
            cout << a << " = ";
            for (int k = 0; k < sum.size() - 1; k++)
            {
                cout << sum[k] << " + ";
            }
            cout << sum.back() << endl; // vector의 가장 마지막 값 구하는 건 .back()함수를 쓰자.
                                        // 내 처음 코드는 sum[sum.size()]였는데, 마지막 값은 sum.size()-1이니 이렇게 해도 된다.
        }
        else
        {
            cout << a << " is NOT perfect." << endl;
        }
    }
}