#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int h1, h2, m1, m2, s1, s2;
    char colon;
    int h, m, s;
    cin >> h1 >> colon >> m1 >> colon >> s1;
    cin >> h2 >> colon >> m2 >> colon >> s2;
    if (s2 < s1)
    {
        m2 -= 1;
        s2 += 60;
        s = s2 - s1;
    }
    else
    {
        s = s2 - s1;
    }
    if (m2 < m1)
    {
        h2 -= 1;
        m2 += 60;
        m = m2 - m1;
    }
    else
    {
        m = m2 - m1;
    }
    if (h2 < h1)
    {
        h2 += 24;
        h = h2 - h1;
    }
    else
    {
        h = h2 - h1;
    }
    printf("%02d:%02d:%02d", h, m, s);
    // iomanip을 include해서 setw와 setfill을 사용해 07:00:09 처럼 출력 OR
    // cstdio를 include해서 printf를 사용하는 것.
}