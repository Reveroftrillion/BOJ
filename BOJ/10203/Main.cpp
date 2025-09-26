#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string str;
        cin >> str;
        int answer = 0;
        for (char c : str)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                answer++;
            }
        }
        cout << "The number of vowels in " << str << " is " << answer << "." << endl;
    }
}