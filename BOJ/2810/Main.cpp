#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string s;
    cin >> N >> s;

    int ans = N + 1;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'L')
        {
            ans--;
            i++;
        }
    }

    if (ans > N)
        ans = N;
    cout << ans;
}