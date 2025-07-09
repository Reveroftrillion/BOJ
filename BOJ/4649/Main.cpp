#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    while (true)
    {
        int beds;
        string events;
        cin >> beds;
        if (beds == 0)
            break;

        cin >> events;
        unordered_set<char> inside;
        unordered_set<char> walked;
        int occupied = 0;

        for (char c : events)
        {
            if (inside.count(c))
            {
                inside.erase(c);
                occupied--;
            }
            else if (walked.count(c))
            {
                continue;
            }
            else
            {
                if (occupied < beds)
                {
                    inside.insert(c);
                    occupied++;
                }
                else
                {
                    walked.insert(c);
                }
            }
        }

        if (walked.empty())
        {
            cout << "All customers tanned successfully." << endl;
        }
        else
        {
            cout << walked.size() << " customer(s) walked away." << endl;
        }
    }
    return 0;
}
