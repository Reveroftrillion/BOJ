#include <iostream>
#include <deque> // 벡터와 비슷하지만 양방향 구조
using namespace std;

int main()
{
    int t;
    cin >> t;
    deque<int> dq;
    deque<int> skills;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        skills.push_front(k);
    }
    for (int i = 0; i < t; i++)
    {

        int k = skills[i];

        if (k == 1)
        {
            dq.push_front(i);
        }
        else if (k == 2)
        {
            if (dq.size() >= 1)
            {
                dq.insert(dq.begin() + 1, i);
            }
            else
            {
                dq.push_front(i);
            }
        }
        else if (k == 3)
        {
            dq.push_back(i);
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout << dq[i] + 1 << " ";
    }
}