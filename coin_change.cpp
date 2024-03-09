#include <iostream>
#include <vector>

using namespace std;

int n, m;

int solve(vector<int> &coins) {
    vector<int> dp(m + 1);
    for (int i = 1; i <= m; i++) {
        dp[i] = 2e9;
        for (int &c : coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    return dp[m];
}

int main() {
    cin >> n >> m;
    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;
    cout << solve(coins) << "\n";
}
