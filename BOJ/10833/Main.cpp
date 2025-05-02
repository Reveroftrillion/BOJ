#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        int stu, apple;
        cin >> stu >> apple;
        sum += apple % stu;
    }
    cout << sum << endl;
}