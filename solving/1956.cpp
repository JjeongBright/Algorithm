#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dist[405][405];
static const int INF = 0x3f3f3f3f;
int main() {

    int V, E; cin >> V >> E;

    for (int i = 1; i <= V; i++) fill(dist[i], dist[i] + V + 1, INF);

    for (int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int i = 1; i <= V; i++) {
        dist[i][i] = 0;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            for (int k = 1; k <= V; k++) {
                dist[j][k] = min(dist[j][k] , dist[j][i] + dist[i][k]);
            }
        }
    }




    if(dist[1][V] == INF) {
        cout << -1;
    } else{ cout << dist[1][V];}

}