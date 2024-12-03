#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> vec[32005];
int deg[32005];
int costArray[505];
int N,M;

void topological_sort(vector<int> &res) {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if(deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (auto nxt: vec[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
            res[nxt] = max(res[nxt], res[cur] + costArray[nxt]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << '\n';
    }

}

int main() {
    cin >> N;
    vector<int> res(N+1);

    for(int i = 1; i <= N; i++) {
        int cost; cin >> cost; costArray[i] = cost;
        int A;
        while (cin >> A) {
            if (A == -1) {
                break;
            }
            vec[A].push_back(i);
            deg[i]++;
        }
        res[i] = costArray[i];
    }

    topological_sort(res);

}