#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n, k;

int solve(vec<int> &nums) {
    vec<int> dp(n, 2e9);
    dp[0] = nums[0];
    for (int i = 1; i <= k; i++) {
        // dp[i] = min(dp[i - 1], nums[i]);
        dp[i] = nums[i];
    }

    for (int i = k + 1; i < n; i++) {
        dp[i] = dp[i - 1] + nums[i];
        for (int j = 1; j <= 2 * k + 1; j++) {
            if (i - j < 0)
                continue;
            dp[i] = min(nums[i - j] + dp[i - j], dp[i]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";

    return dp[n - 1];
}

int main() {
    cin >> n >> k;
    vec<int> nums(n);
    for (int &n : nums)
        cin >> n;
    cout << solve(nums) << "\n";
}

/*
10 3
260 241 865 354 3 626 225 335 243 405
 */
