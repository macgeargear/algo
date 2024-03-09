#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, w;
vector<int> N, W;

ll solve() {
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || w == 0)
                dp[i][j] = 0;
            else if (W[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + N[i - 1]);
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= w; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return dp[n][w];
}

int main() {
    cin >> n >> w;
    N.resize(n);
    W.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i] >> N[i];
    }
    cout << solve();
}
