#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (str.length() <= 9 && str.length() >= 6)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}