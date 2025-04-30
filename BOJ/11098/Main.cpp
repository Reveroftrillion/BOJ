#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        int max = 0;
        string c;
        for (int j = 0; j < k; j++)
        {
            int money;
            string name;
            cin >> money;
            cin >> name;
            if (money > max)
            {
                c = name;
                max = money;
            }
        }
        cout << c << endl;
    }
}