#include <iostream>
using namespace std;

int main()
{
    int A[10], B[10];
    int scoreA = 0, scoreB = 0;
    char lastWin = 'D';

    for (int i = 0; i < 10; i++)
        cin >> A[i];
    for (int i = 0; i < 10; i++)
        cin >> B[i];

    for (int i = 0; i < 10; i++)
    {
        if (A[i] > B[i])
        {
            scoreA += 3;
            lastWin = 'A';
        }
        else if (A[i] < B[i])
        {
            scoreB += 3;
            lastWin = 'B';
        }
        else
        {
            scoreA += 1;
            scoreB += 1;
        }
    }

    cout << scoreA << " " << scoreB << "\n";

    if (scoreA > scoreB)
        cout << "A\n";
    else if (scoreA < scoreB)
        cout << "B\n";
    else
        cout << lastWin << "\n";

    return 0;
}
