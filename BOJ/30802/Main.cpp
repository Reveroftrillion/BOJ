#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> array;
    for (int i = 0; i < 6; i++)
    {
        int a;
        cin >> a;
        array.push_back(a);
    }
    int shirt, pen;
    cin >> shirt >> pen;
    int num = 0;
    for (int j = 0; j < 6; j++)
    {
        if (array[j] % shirt == 0)
        {
            num += array[j] / shirt;
        }
        else
        {
            num += array[j] / shirt + 1;
        }
    }
    int pen_ = t / pen;
    int pen__ = t % pen;
    cout << num << endl;
    cout << pen_ << " " << pen__ << endl;
}