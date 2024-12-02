#include <iostream>
using namespace std;
int arr[105];
int dp[105];
int main() {

    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        arr[num] = 1;
    }
}