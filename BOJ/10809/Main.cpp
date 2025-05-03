#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string ch;
    cin >> ch;
    vector<int> array(26, -1); // 배열 안에 전부 -1로 채우기
    for (int i = 0; i < ch.size(); i++)
    {
        int index = ch[i] - 'a'; // a부터 z까지 0부터 25로 만들어준다. 원래 코드는 a부터 z까지 전부 비교하는 형식 => 비효율적
        if (array[index] == -1)
        {
            array[index] = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << array[i] << " ";
    }
}