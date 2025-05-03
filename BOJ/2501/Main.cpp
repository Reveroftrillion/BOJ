#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> array;
    int a, b;
    cin >> a >> b;
    for (int i = 1; i < a + 1; i++)
    {
        if (a % i == 0)
        {
            array.push_back(i);
        }
    }
    if (array.size() < b)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << array[b - 1] << endl;
    }
}