#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        long long sum = 0;
        for (int j = 0; j < k; j++)
        {
            long long l;
            cin >> l;
            sum = (sum + l) % k; // 미리 나머지만 남겨서 오버플로우 발생 방지
        }
        if (sum % k == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}