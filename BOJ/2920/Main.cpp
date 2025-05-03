#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> array(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> array[i]; // cin은 입력받을 변수의 타입을 기준으로 자동 형 변환을 시도한다.
    }

    bool ascend = true;
    bool descend = true;

    for (int j = 0; j < 8; j++)
    {
        if (array[j] != j + 1) // 여기서 boolean값들을 결정하고
        {
            ascend = false;
        }
        if (array[j] != 8 - j)
        {
            descend = false;
        }
    }

    if (ascend) // if문의 조건으로 boolean값을 설정
    {
        cout << "ascending" << endl;
    }
    else if (descend)
    {
        cout << "descending" << endl;
    }
    else
    {
        cout << "mixed" << endl;
    }
}