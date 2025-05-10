#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<string> name;
    bool inc = true;
    bool dec = true;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        name.push_back(str);
    }
    for (int j = 0; j < name.size() - 1; j++)
    {
        if (name[j] > name[j + 1])
        {
            inc = false;
        }
        else if (name[j] < name[j + 1])
        {
            dec = false;
        }
    }
    if (inc)
    {
        cout << "INCREASING" << endl;
    }
    else if (dec)
    {
        cout << "DECREASING" << endl;
    }
    else
    {
        cout << "NEITHER" << endl;
    }
}