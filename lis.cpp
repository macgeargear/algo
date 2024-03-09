#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n;

int solve(vec<int> &nums) {
    vec<int> dp(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j - 1] < nums[i - 1]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(dp[i], ans);
            }
        }
    }
    return ans;
}

int main() {
    cin >> n;
    vec<int> nums(n);
    for (int &n : nums)
        cin >> n;

    cout << solve(nums) << "\n";
}
