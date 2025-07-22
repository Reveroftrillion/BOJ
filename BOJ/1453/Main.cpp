#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int answer = 0;
    vector<bool> pcbang = {false};
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        if (!pcbang[k])
        {
            pcbang[k] = true;
        }
        else if (pcbang[k])
        {
            answer++;
        }
    }
    cout << answer << endl;
}