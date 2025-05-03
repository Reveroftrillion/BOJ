#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> array;
    for (int i = 0; i < 7; i++)
    {
        int t;
        cin >> t;
        if (t % 2 == 1)
        {
            array.push_back(t);
        }
    }
    if (array.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < array.size(); i++)
        {
            sum += array[i];
        }
        int min = *min_element(array.begin(), array.end()); // vector안에 있는 최솟값 출력 : *min_element
        cout << sum << endl;
        cout << min << endl;
    }
}