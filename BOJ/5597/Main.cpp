#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> array(30);
    for (int i = 0; i < 30; i++)
    {
        array[i] = i + 1;
    }
    for (int k = 0; k < 28; k++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < array.size(); j++) // 30으로 지정하는 것보다 array.size로 바꾸는게 안전하다.
        {
            if (array[j] == a)
            {
                array.erase(array.begin() + j);
                break; // erase했으니 빠져나와줘야함.
            }
        }
    }
    sort(array.begin(), array.end());
    for (int l = 0; l < 2; l++)
    {
        cout << array[l] << endl;
    }
}