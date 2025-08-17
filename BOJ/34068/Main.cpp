#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int M;
    cin >> N >> M;

    vector<int> scores(N + 1, 0);

    for (int i = 0; i < M; ++i)
    {
        int winner, loser;
        cin >> winner >> loser;
        scores[winner]++;
    }

    vector<int> current_scores;
    current_scores.reserve(N);
    for (int i = 1; i <= N; ++i)
    {
        current_scores.push_back(scores[i]);
    }

    sort(current_scores.begin(), current_scores.end());

    long long additional_duels = 0;
    long long target_score = 0;

    for (int score : current_scores)
    {
        long long new_score = max((long long)score, target_score);
        additional_duels += new_score - score;
        target_score = new_score + 1;
    }

    cout << additional_duels << endl;

    return 0;
}