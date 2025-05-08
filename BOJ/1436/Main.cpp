#include <iostream>
using namespace std;

void apocalypse(int a)
{
    int cnt = 0;
    long long number = 666;
    while (true)
    {
        if (to_string(number).find("666") != string::npos) // string::npos : 문자열에서 찾지 못했을 때를 나타낸다. 여기선 666을 찾았을 때로 사용.
        {
            cnt++;
            if (cnt == a)
            {
                cout << number << endl;
                break;
            }
        }
        number++;
    }
}

int main()
{
    int t;
    cin >> t;
    apocalypse(t);
}