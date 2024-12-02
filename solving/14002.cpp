#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;
int N;
int arr[1005];
int DP[1005];
int main() {
    io;
    cin >> N;
    int res = 1;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        DP[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[i] > arr[j]){
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        res = max(res, DP[i]);
    }
    vector<int> chk;

    for (int i = N-1; i >= 0; i--) {
        if(DP[i] == res) {
            chk.push_back(arr[i]);
            res--;
        }
    }

    reverse(chk.begin(), chk.end());
    cout << chk.size() << '\n';
    for (auto x: chk) {
        cout << x << ' ';
    }

}