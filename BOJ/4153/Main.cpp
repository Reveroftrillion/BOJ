#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> array; // 크기를 3으로 지정하고 push back하면 000abc이렇게 6짜리가 되니까 크기 지정하지 말자.
        array.push_back(a);
        array.push_back(b);
        array.push_back(c);
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        else
        {
            // *min_element나 *max_element 쓰려면 algorithm include 해야 한다.
            // 그렇지만, sort를 통해서 그냥 작은 것부터 큰 걸로 정렬하면 된다.
            sort(array.begin(), array.end());
            int min = array[0];
            int mid = array[1];
            int max = array[2];

            if (min * min + mid * mid == max * max)
            {
                cout << "right" << endl;
            }
            else
            {
                cout << "wrong" << endl;
            }
        }
    }
}