#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

int longest_sub_len(vector<int> &nums) {
    int n = nums.size();
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = 0;
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[0] + 1;
        for (int j = 0; j < i; j++) {
            if (nums[j - 1] < nums[i - 1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int lis_bs(vector<int> &nums) {
    int n = nums.size();
    int dp[n + 1];
    dp[0] = -INFINITY;
    for (int i = 1; i <= n; i++)
        dp[i] = INFINITY;
    for (int i = 0; i < n; i++) {
        int idx = upper_bound(dp, dp + n + 1, nums[i]) - dp;
        if (dp[idx - 1] < nums[i] && nums[i] < dp[idx])
            dp[idx] = nums[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != INFINITY)
            ans = i;
    }
    return ans;
}

int main() {
}
