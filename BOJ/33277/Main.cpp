#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    double percent = (double)b / a;
    int time = percent * 24 * 60;
    int hour = time / 60;
    int minute = time % 60;
    cout << hour << ":" << minute << endl;
}