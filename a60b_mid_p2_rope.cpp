#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, a, b, c;

int solve(int n, vector<int> &nums) {
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = -2e9;
        for (int &x : nums) {
            if (i - x >= 0) {
                dp[i] = max(dp[i], dp[i - x] + 1);
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";

    return dp[n];
}

int main() {
    cin >> n >> a >> b >> c;
    vector<int> nums = {a, b, c};
    cout << solve(n, nums) << "\n";
}
