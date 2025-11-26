#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L;
    if (!(cin >> L))
        return 0;
    string str;
    cin >> str;

    vector<int> pi(L, 0);
    for (int i = 1; i < L; i++)
    {
        // 이전 위치까지의 최대 일치 길이
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j])
        {
            // 최대 일치 길이를 유지하지 못함
            // 더 짧지만 가능한 접두사의 길이로 업데이트
            j = pi[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        pi[i] = j;
    }

    int answer = L - pi[L - 1];
    cout << answer << endl;
}