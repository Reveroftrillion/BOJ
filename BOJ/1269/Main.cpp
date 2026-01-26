#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    unordered_set<int> setA;
    for (int i = 0; i < A; i++)
    {
        int x;
        cin >> x;
        setA.insert(x);
    }

    int common = 0;
    for (int i = 0; i < B; i++)
    {
        int x;
        cin >> x;
        if (setA.count(x))
            common++;
    }

    cout << (A - common) + (B - common) << '\n';
}
