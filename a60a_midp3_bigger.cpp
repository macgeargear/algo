#include <iostream>
#include <vector>

using namespace std;

int n;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int solve(vector<int> &nums) {
    vector<int> dp(n);
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    if (n == 3)
        return max(max(nums[0], nums[1]), nums[2]);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    dp[2] = max(max(nums[0], nums[1]), nums[2]);

    for (int i = 3; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2], dp[i - 3] + nums[i]);

    return dp[n - 1];
}

int main() {
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums)
        cin >> n;
    cout << solve(nums) << "\n";
}
