#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dist[205][205];
vector<int> isAvailable;
static const int INF = 0x3f3f3f3f;
int main() {

    int N, M; cin >> N >> M;

    for (int i = 1; i <= N; i++)
        fill(dist[i], dist[i] + 1 + N, INF);

    while (M--) {
        int A, B, T; cin >> A >> B >> T;
        dist[A][B] = min(dist[A][B], T);
    }

    for (int i = 1; i <= N; i++) dist[i][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    int K; cin >> K;
    while(K--) {
        int C; cin >> C;
        isAvailable.push_back(C);
    }

    vector<pair<int,int>> vec;
    for (int i = 1; i <= N; i++) {
        int mx = 0;
        for(int x : isAvailable) {
            mx = max(mx, dist[i][x] + dist[x][i]);
        }
        vec.push_back({mx, i});
    }

    sort(vec.begin(), vec.end());
    int mn = vec[0].first;
    for (auto cur: vec) {
        if(mn < cur.first) break;
        cout << cur.second << ' ';
    }

}