#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int answer = 0;
    map<string, int> moolpum;
    for (int i = 0; i < N; i++)
    {
        string name;
        int price;
        float checking;
        cin >> name >> price;
        checking = price * 1.05;
        // 이것만 알았으면 풀 수 있었는데;;;
        // map[key] = value 또는 pair 객체 써서 삽입할 수 있다.
        moolpum[name] = checking;
    }
    for (int i = 0; i < M; i++)
    {
        string name1;
        int doubt;
        cin >> name1 >> doubt;
        if (moolpum[name1] < doubt)
        {
            answer++;
        }
    }
    cout << answer << endl;
}