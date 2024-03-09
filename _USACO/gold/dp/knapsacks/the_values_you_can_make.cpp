#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n, k;

void solve(vec<int> &coins, int k) {
    vec<vec<bool>> dp(n + 1, vec<bool>(k + 1));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int price = k; price >= 0; price--) {
            if (price - coins[i] < 0)
                continue;
            for (int sum = price - coins[i]; sum >= 0; sum--) {
                if (dp[price - coins[i]][sum]) {
                    dp[price][sum + coins[i]] = true;
                    dp[price][sum] = true;
                }
            }
        }
    }

    vector<int> ans;
    for (int sum = 0; sum <= k; sum++) {
        if (dp[k][sum])
            ans.push_back(sum);
    }
}

int main() {
    cin >> n >> k;
    vec<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    solve(coins, k);
}
