#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> array;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        array.push_back(a);
        array.push_back(b);
        array.push_back(c);
        array.push_back(d);
        sort(array.begin(), array.end());
        bool check = false;

        if (array == vector<int>{0, 1, 2, 3} ||
            array == vector<int>{0, 2, 4, 6} ||
            array == vector<int>{0, 1, 4, 5} ||
            array == vector<int>{1, 3, 5, 7} ||
            array == vector<int>{2, 3, 6, 7} ||
            array == vector<int>{4, 5, 6, 7}) // 이렇게 한 번에 정리할 수도 있다.
        {
            check = true;
        }

        if (check)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}