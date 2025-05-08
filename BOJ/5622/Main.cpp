#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int sum = 0;
    for (char c : str)
    {
        if (c == 'A' || c == 'B' || c == 'C')
            sum += 3;
        if (c == 'D' || c == 'E' || c == 'F')
            sum += 4;
        if (c == 'G' || c == 'H' || c == 'I')
            sum += 5;
        if (c == 'J' || c == 'K' || c == 'L')
            sum += 6;
        if (c == 'M' || c == 'N' || c == 'O')
            sum += 7;
        if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
            sum += 8;
        if (c == 'T' || c == 'U' || c == 'V')
            sum += 9;
        if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
            sum += 10;
    }
    cout << sum << endl;
}