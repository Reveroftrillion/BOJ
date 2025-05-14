#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin >> k;
    deque<long long> card;
    for (long long i = 1; i < k + 1; i++)
    {
        card.push_back(i);
    }
    while (card.size() > 1)
    {
        card.pop_front();
        card.push_back(card.front());
        card.pop_front();
    }
    cout << card[0] << endl;
}