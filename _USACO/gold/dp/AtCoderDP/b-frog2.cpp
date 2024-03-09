#include <iostream>
#include <vector>

using namespace std;

int n, k;

int solve(vector<int> &nums) {
    vector<int> dp(n, 2e9);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = 2e9;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(nums[i] - nums[i - j]));
            }
        }
    }

    return dp[n - 1];
}

int main() {
    cin >> n >> k;
    vector<int> nums(n);
    for (int &n : nums)
        cin >> n;

    cout << solve(nums);
}
