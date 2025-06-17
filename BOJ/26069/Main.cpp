#include <iostream>
#include <set>
using namespace std;

int main()
{
    int k;
    cin >> k;
    set<string> rainbow;
    rainbow.insert("ChongChong");
    for (int i = 0; i < k; i++)
    {
        string A, B;
        cin >> A >> B;
        for (string str : rainbow)
        {
            if (A == str)
            {
                rainbow.insert(B);
            }
            if (B == str)
            {
                rainbow.insert(A);
            }
        }
    }
    cout << rainbow.size() << endl;
}