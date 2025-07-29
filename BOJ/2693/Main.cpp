#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        vector<int> testCases;
        for(int j = 0; j < 10; j++){
            int k;
            cin >> k;
            testCases.push_back(k);
        }
        sort(testCases.begin(), testCases.end(), greater<int>());
        cout << testCases[2] << endl;
    }
}
