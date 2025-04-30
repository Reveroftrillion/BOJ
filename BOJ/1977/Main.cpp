#include <iostream>
#include <vector>
using namespace std;

int square(int a, int b)
{
    vector<int> vec; // 크기 지정 안할꺼면 push_back 써야하고, 크기 지정하면 vec[i] 이런 식으로 써야함
    vector<int> min;
    int sum = 0;
    for (int i = 1; i < 101; i++)
    {
        vec.push_back(i * i);
    }

    for (int i = a; i <= b; i++) // a <= i <= b 이건 파이썬에서만 사용가능. 그러니 int i = a; i <= b로 고쳐야 함
    {
        for (int j = 0; j < 100; j++)
        {
            if (vec[j] == i)
            {
                sum += vec[j];
                min.push_back(vec[j]);
            }
        }
    }
    if (min.empty()) // min이 비어있을 때, -1 출력해야하니까, empty라는 함수로 확인 한 번 해주기.
        cout << -1 << endl;
    else
    {
        cout << sum << endl;
        cout << min[0] << endl; // vector에서 최소값을 구하는 건 for문 사용, int min = *min_element(v.begin(), v.end()); 이 문장 사용 등이 있지만..
                                // 이번 min은 작은 순서대로 들어오니 맨 앞을 출력해준다.
    }
    return 0; // return 값이 없는 함수는 오류가 날 수 있다.
}

int main()
{
    int A, B;
    cin >> A >> B;
    square(A, B);
}