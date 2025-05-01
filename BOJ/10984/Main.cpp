#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int cases;
        cin >> cases;
        int classes = 0;
        float GPA = 0;
        for (int j = 0; j < cases; j++)
        {
            int a;
            float b;
            cin >> a >> b;
            classes += a;
            GPA += a * b;
        }
        cout << fixed;     // fixed를 사용해서 숫자를 고정 소숫점 방식으로 출력하도록 한다.
        cout.precision(1); // precision 안의 숫자만큼의 자릿수로 표시하도록 한다.
        cout << classes << " " << GPA / classes << endl;
    }
}