#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    int num = 0;
    for (int i = 0; i < 5; i++)
    {
        char k;
        cin >> k;
        if (c == k)
        {
            num++;
        }
    }
    cout << num << endl;
}