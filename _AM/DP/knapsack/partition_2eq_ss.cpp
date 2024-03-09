#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n;

bool can_partition(vec<int> &nums, int sum) {
    if (sum % 2 != 0)
        return false;
    int target = sum / 2;
    vec<vec<bool>> dp(n + 1, vec<bool>(target + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= target; s++) {
            if (s - nums[i] >= 0)
                dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i - 1]];
            else
                dp[i][s] = dp[i - 1][s];
        }
    }
    return dp[n][target];
}
int main() {
    cin >> n;
    int sum = 0;
    vec<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    cout << (can_partition(nums, sum) ? "true\n" : "false\n");
}
