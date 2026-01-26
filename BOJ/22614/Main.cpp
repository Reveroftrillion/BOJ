#include <bits/stdc++.h>
using namespace std;

struct Packet {
    long long t;
    int s, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<Packet> packets(M);
        for (int i = 0; i < M; i++) {
            cin >> packets[i].t >> packets[i].s >> packets[i].d;
        }

        // 시간 순 정렬
        sort(packets.begin(), packets.end(),
             [](const Packet& a, const Packet& b) {
                 return a.t < b.t;
             });

        vector<bool> infected(N + 1, false);
        infected[1] = true;

        for (auto &p : packets) {
            if (infected[p.s]) {
                infected[p.d] = true;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (infected[i]) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}
