#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int answer = 0;
    vector<int> plastic(10);
    for (char c : str)
    {
        if (c == '9')
            plastic[6]++;
        else
        {
            plastic[c - '0']++;
        }
    }
    plastic[6] = (plastic[6] + 1) / 2; // 이거 올림 처리 해줘야 한다.
    cout << *max_element(plastic.begin(), plastic.end()) << endl;
}