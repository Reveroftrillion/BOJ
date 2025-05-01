#include <iostream>
using namespace std;

int main()
{
    int Max_num = 0;
    int train = 0;
    for (int i = 0; i < 10; i++)
    {
        int A, B;
        cin >> A >> B;
        train -= A;
        train += B;
        if (train > Max_num)
        {
            Max_num = train;
        }
    }
    cout << Max_num << endl;
}