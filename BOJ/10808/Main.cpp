#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int arr[26] = {0};
    for (char c : str)
    {
        arr[c - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
}