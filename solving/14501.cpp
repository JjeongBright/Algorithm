#include <iostream>
using namespace std;
int days[19], money[19];
int dp[19];
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> days[i] >> money[i];
    }

    int res = 0;
    for (int i = N - 1; i >= 0; i--) {
        if(days[i] + i <= N) {
            dp[i] = max(dp[i+1], dp[i + days[i]] + money[i]);
        } else dp[i] = dp[i + 1];
        res = max(res, dp[i]);
    }
    cout << res;
}