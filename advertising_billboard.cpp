#include <iostream>
#include <vector>

using namespace std;

int n;

int solve(vector<int> &nums) {
    vector<int> dp(n);
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

    return dp[n - 1];
}

int main() {
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums)
        cin >> n;
    cout << solve(nums) << "\n";
}
