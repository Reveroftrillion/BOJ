#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long total_price = 0;
    string name;

    while (true)
    {
        if (!getline(cin, name))
            break; // EOF
        if (name == "TOTAL")
            break;

        string line;
        if (!getline(cin, line))
            break;

        long long p, c;
        istringstream iss(line);
        iss >> p >> c;

        total_price += p * c;
    }

    long long T;
    if (!(cin >> T))
        return 0;

    if (T <= total_price)
        cout << "PAY\n";
    else
        cout << "PROTEST\n";

    return 0;
}
