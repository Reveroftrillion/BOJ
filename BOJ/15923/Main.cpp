#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> boundary1;
    vector<int> boundary2;
    int answer = 0;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        boundary1.push_back(a);
        boundary2.push_back(b);
    }
    for (int i = 0; i < k; i++)
    {
        if (i == 0)
        {
            answer += (abs(boundary1[i] - boundary1[k - 1]) + abs(boundary2[0] - boundary2[k - 1]));
        }
        else
        {
            answer += (abs(boundary1[i] - boundary1[i - 1]) + abs(boundary2[i] - boundary2[i - 1]));
        }
    }
    cout << answer << endl;
}