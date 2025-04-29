#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        string university;
        int alcol = 0;
        for (int j = 0; j < num; j++)
        {
            string c;
            cin >> c;
            int a;
            cin >> a;
            if (a > alcol)
            {
                university = c;
                alcol = a;
            }
        }
        cout << university << endl;
    }
}