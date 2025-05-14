#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int time = b * 1440 / a;
    int hour = time / 60;
    int minute = time % 60;
    cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << endl;
}