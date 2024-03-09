#include <iostream>
#include <vector>

using namespace std;

int n, x;

const int M = (int)1e9 + 7;

// dp[w] = dp[w] + dp[w-coins[i]] for 0 <= w <= x
int solve(vector<int> &coins, int x) {
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= x; w++) {
            if (w - coins[i] >= 0) {
                dp[w] += dp[w - coins[i]];
                dp[w] %= M;
            }
        }
    }

    // for (int i = 0; i <= x; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    return dp[x];
}

int main() {
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;
    cout << solve(coins, x) << "\n";
}
