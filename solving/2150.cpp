#include <bits/stdc++.h>
using namespace std;

vector<int> vec[10005];
vector<int> temp, revVec[10005];
vector<int> scc[10005];
stack<int> stk;
bool visited[10005], rvisited[10005];
int idx = 1;

static bool cmp(vector<int> &a, vector<int> &b) {
    if(a.empty()) return false;
    if(b.empty()) return true;
    return a[0] < b[0];
}


void dfs(int st) {
    if(visited[st]) return;

    visited[st] = true;

    for (auto x: vec[st]) {
        if(visited[x]) continue;
        dfs(x);
    }
    stk.push(st);
}

void reverseDfs(int std, int st) {
    if(rvisited[st]) return;

    rvisited[st] = true;
    scc[std].push_back(st);

    for (auto x: revVec[st]) {
        if(rvisited[x]) continue;
        reverseDfs(std, x);
    }

}

int main() {

    int V, E; cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int A, B; cin >> A >> B;
        vec[A].push_back(B);
        revVec[B].push_back(A);
    }
    for(int i = 1; i <= V; i++) dfs(i);

    int sccCnt = 0;
    while (!stk.empty()) {
        int stkInt = stk.top();
        stk.pop();
        if(rvisited[stkInt]) continue;

        reverseDfs(sccCnt, stkInt);
        sccCnt++;
    }

    cout << sccCnt++ << '\n';

    for (int i = 0; i < sccCnt; i++) {
        sort(scc[i].begin(), scc[i].end());
    }

    sort(scc, scc + sccCnt, cmp);

    for (int i = 0; i < sccCnt - 1; i++) {
        for (auto x: scc[i]) {
            cout << x << ' ';
        }
        cout << -1 << '\n';
    }

}

