#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, int> dictionary;
    string word;

    for (int i = 0; i < n; ++i)
    {
        cin >> word;
        dictionary[word]++;
    }

    int maxFreq = 0;
    string result = "";

    for (auto &entry : dictionary)
    {
        if (entry.second > maxFreq ||
            (entry.second == maxFreq && entry.first > result))
        {
            maxFreq = entry.second;
            result = entry.first;
        }
    }

    cout << result << " " << maxFreq << endl;

    return 0;
}
