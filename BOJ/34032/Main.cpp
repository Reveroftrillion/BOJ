#include <iostream>
using namespace std;

int main()
{
    int N;
    string str;
    cin >> N >> str;
    double checking = N / (double)2;
    int cnt = 0;
    for (char c : str)
    {
        if (c == 'O')
        {
            cnt++;
        }
    }
    if (cnt < checking)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}