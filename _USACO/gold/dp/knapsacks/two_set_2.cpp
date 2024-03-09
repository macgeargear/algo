#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n;
const int M = 1e9 + 7;

int solve(int sum) {
    if (sum % 2 != 0)
        return 0;
    int target = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= target; s++) {
            if (s - i + 1 >= 0)
                dp[i][s] = dp[i - 1][s] + dp[i - 1][s - i + 1];
            else
                dp[i][s] = dp[i - 1][s];
            dp[i][s] %= M;
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= target; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][target];
}

int main() {
    cin >> n;
    int sum = n * (n + 1) / 2;
    cout << solve(sum) << "\n";
}
