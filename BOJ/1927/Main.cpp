#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    priority_queue<int, vector<int>, greater<int>> pq; // priority queue는 원래 큰 거부터 나오니까 반대로 정렬
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            if (pq.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(k);
        }
    }
}