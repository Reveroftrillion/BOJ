#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> friends(1000, 0);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a] += 1;
        friends[b] += 1;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << friends[i] << '\n';
    }
}