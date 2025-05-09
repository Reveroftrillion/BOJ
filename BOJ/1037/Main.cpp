#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> yak;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        yak.push_back(k);
    }

    sort(yak.begin(), yak.end()); // sort하면 반복자를 안에 넣어줘야한다. begin, end (iterator는 위치 정보를 뜻함)

    if (t == 1)
    {
        cout << yak[0] * yak[0] << endl;
    }
    else if (t % 2 == 0)
    {
        cout << yak[0] * yak[yak.size() - 1] << endl;
    }
    else if (t % 2 != 0)
    {
        cout << yak[(yak.size() - 1) / 2] * yak[(yak.size() - 1) / 2] << endl;
    }
}