#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> nums;
    stringstream ss(s);
    string part;

    while (getline(ss, part, '-'))
    {
        stringstream ps(part);
        string num;
        int sum = 0;

        while (getline(ps, num, '+'))
        {
            sum += stoi(num);
        }
        nums.push_back(sum);
    }

    int result = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i)
        result -= nums[i];

    cout << result;
    return 0;
}
