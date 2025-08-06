#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    int answer = 0;
    int trash = 0;
    vector<int> sandwich;
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        sandwich.push_back(k);
    }
    for (int a : sandwich)
    {
        int k = a / X;
        answer += k;

        if (k == 0)
        {
            trash += a;
        }
        else
        {
            int can_be_trash = a - k * Y;
            if (can_be_trash > 0)
                trash += can_be_trash;
        }
    }

    cout << answer << endl
         << trash << endl;
}