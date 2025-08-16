#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calculate_distance(const vector<string> &fp1, const vector<string> &fp2)
{
    int distance = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (fp1[i][j] != fp2[i][j])
            {
                distance++;
            }
        }
    }
    return distance;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;

    vector<vector<string>> database(n, vector<string>(5));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> database[i][j];
        }
    }

    for (int k = 1; k <= K; ++k)
    {
        vector<string> crime_fp(5);
        for (int i = 0; i < 5; ++i)
        {
            cin >> crime_fp[i];
        }

        int min_distance = 26;
        vector<int> best_matches;

        for (int i = 0; i < n; ++i)
        {
            int current_distance = calculate_distance(crime_fp, database[i]);

            if (current_distance < min_distance)
            {
                min_distance = current_distance;
                best_matches.clear();
                best_matches.push_back(i + 1);
            }
            else if (current_distance == min_distance)
            {
                best_matches.push_back(i + 1);
            }
        }

        cout << "Data Set " << k << ":\n";
        for (size_t i = 0; i < best_matches.size(); ++i)
        {
            cout << best_matches[i] << (i == best_matches.size() - 1 ? "" : " ");
        }
        cout << "\n\n";
    }

    return 0;
}